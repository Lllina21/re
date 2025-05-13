#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include <vector>

using namespace cv;
using namespace std;

void drawChessboard(int rows, int cols, int cellSize) {
    Mat img(rows * cellSize, cols * cellSize, CV_8UC3, Scalar(255, 255, 255));

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if ((i + j) % 2 == 0)
                rectangle(img, Point(j * cellSize, i * cellSize),
                          Point((j + 1) * cellSize, (i + 1) * cellSize),
                          Scalar(0, 0, 0), FILLED);

    imwrite("chessboard.png", img);
    cout << "Saved chessboard.png\n";
}

void drawSpiral(int width, int height, int step, int thick, Scalar color) {
    Mat img(height, width, CV_8UC3, Scalar(255, 255, 255));
    int left = width / 2, right = width / 2;
    int top = height / 2, bottom = height / 2;

    Point pt(width / 2, height / 2);

    int dx[] = {1, 0, -1, 0}; // right, down, left, up
    int dy[] = {0, 1, 0, -1};

    int dir = 0;
    int len = step;

    for (int i = 0; i < 1000; ++i) {
        Point next = pt + Point(dx[dir] * len, dy[dir] * len);
        line(img, pt, next, color, thick);
        pt = next;
        dir = (dir + 1) % 4;
        if (dir == 0 || dir == 2) len += step;
        if (pt.x < 0  || pt.x >= width  || pt.y < 0 || pt.y >= height) break;
    }

    imwrite("spiral.png", img);
    cout << "Saved spiral.png\n";
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) elems.push_back(item);
    return elems;
}

int main(int argc, char** argv) {
    map<string, string> args;
    for (int i = 1; i < argc - 1; ++i)
        if (string(argv[i]).substr(0, 2) == "--")
            args[string(argv[i]).substr(2)] = argv[i + 1];

    if (args.count("rows") && args.count("cols") && args.count("cell"))
        drawChessboard(stoi(args["rows"]), stoi(args["cols"]), stoi(args["cell"]));
    else if (args.count("width") && args.count("height") && args.count("thick") &&
             args.count("step") && args.count("color")) {
        vector<string> col = split(args["color"], ',');
        Scalar color(stoi(col[2]), stoi(col[1]), stoi(col[0]));
        drawSpiral(stoi(args["width"]), stoi(args["height"]),
                   stoi(args["step"]), stoi(args["thick"]), color);
    } else {
        cout << "Invalid arguments\n";
    }

    return 0;
}