/**
 * This program is not really easy to read. Sorry for that.
 * But you should read doc about rubik cube and try to implement your own solution.
 * It is funny.
 *
 * The contest the program originated from: http://maratona.ime.usp.br/hist/2002/
 * You can submit solutions here: https://www.urionlinejudge.com.br/judge/en/problems/view/1339
 * Another solution can be found here: https://github.com/lucassf/UVA-Solutions
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

const int faceSize = 3;

struct Face;

struct Side {
    struct Face *face;
    string type;
    int index;
    Side();
    Side(struct Face *, const char *, int);
    vector<char> getContent();
    void setContent(const vector<char> &);
};

struct Face {
    vector<char> content;
    Side top, left, bottom, right;

    Face(): content(faceSize * faceSize, 0), top(), left(), bottom(), right() {}

    char & operator ()(const int &i, const int &j) {
        return content.at(i * faceSize + j);
    }

    bool hasOneColor() {
        auto ref = (*this)(0, 0);
        return all_of(content.begin(), content.end(), [&ref](const char &ch) -> bool {
            return ch == ref;
        });
    }

    void setColumn(int col, const vector<char> &v) {
        for (int j = 0; j < faceSize; ++j) {
            (*this)(j, col) = v.at(j);
        }
    }

    vector<char> getColumn(int col) {
        vector<char> v;
        for (int j = 0; j < faceSize; ++j) {
             v.push_back((*this)(j, col));
        }
        return v;
    }

    void setRow(int row, const vector<char> &v) {
        for (int j = 0; j < faceSize; ++j) {
            (*this)(row, j) = v.at(j);
        }
    }

    vector<char> getRow(int row) {
        vector<char> v;
        for (int j = 0; j < faceSize; ++j) {
             v.push_back((*this)(row, j));
        }
        return v;
    }

    vector<char> getLeftColumn() {
        return getColumn(0);
    }

    void setLeftColumn(const vector<char> &v) {
        setColumn(0, v);
    }

    vector<char> getRightColumn() {
        return getColumn(faceSize - 1);
    }

    void setRightColumn(const vector<char> &v) {
        setColumn(faceSize - 1, v);
    }

    vector<char> getTopRow() {
        return getRow(0);
    }

    void setTopRow(const vector<char> &v) {
        setRow(0, v);
    }

    vector<char> getBottomRow() {
        return getRow(faceSize - 1);
    }

    void setBottomRow(const vector<char> &v) {
        setRow(faceSize - 1, v);
    }

    void rotateContentCw() {
        auto right = getRightColumn();
        auto left = getLeftColumn();
        auto bottom = getBottomRow();
        auto top = getTopRow();

        setRightColumn(top);
        reverse(right.begin(), right.end());
        setBottomRow(right);
        setLeftColumn(bottom);
        reverse(left.begin(), left.end());
        setTopRow(left);
    }
};

using Face = struct Face;

Side::Side(): face(NULL), type("") {
    index = -1;
}

Side::Side(Face *f, const char *s, int i): face(f), type(s) {
    index = i;
}

vector<char> Side::getContent() {
    vector<char> v;
    if (type == "row") {
        for (int j = 0; j < faceSize; ++j) {
            v.push_back((*face)(index, j));
        }
    } else {
        for (int j = 0; j < faceSize; ++j) {
            v.push_back((*face)(j, index));
        }
    }
    return v;
}

void Side::setContent(const vector<char> &v) {
    for (int j = 0; j < faceSize; ++j) {
        if (type == "row") {
            (*face)(index, j) = v.at(j);
        } else {
            (*face)(j, index) = v.at(j);
        }
    }
}

Face faces[6];

void rotateFaceCw(int number) {
    auto &face = faces[number];
    auto top = face.top.getContent();
    auto bottom = face.bottom.getContent();
    auto left = face.left.getContent();
    auto right = face.right.getContent();

    face.rotateContentCw();
    switch (abs(number)) {
    case 0:
        face.right.setContent(top);
        face.bottom.setContent(right);
        reverse(bottom.begin(), bottom.end());
        face.left.setContent(bottom);
        reverse(left.begin(), left.end());
        face.top.setContent(left);
        break;
    case 1:
        face.right.setContent(top);
        reverse(right.begin(), right.end());
        face.bottom.setContent(right);
        face.left.setContent(bottom);
        reverse(left.begin(), left.end());
        face.top.setContent(left);
        break;
    case 2:
        reverse(top.begin(), top.end());
        face.right.setContent(top);
        reverse(right.begin(), right.end());
        face.bottom.setContent(right);
        face.left.setContent(bottom);
        face.top.setContent(left);
        break;
    case 3:
        reverse(top.begin(), top.end());
        face.right.setContent(top);
        face.bottom.setContent(right);
        reverse(bottom.begin(), bottom.end());
        face.left.setContent(bottom);
        face.top.setContent(left);
        break;
    case 4:
        face.right.setContent(top);
        face.bottom.setContent(right);
        face.left.setContent(bottom);
        face.top.setContent(left);
        break;
    case 5:
        face.right.setContent(top);
        face.bottom.setContent(right);
        face.left.setContent(bottom);
        face.top.setContent(left);
        break;
    }
}

void rotateFaceCcw(int number) {
    for (int j = 0; j < 3; ++j) {
        rotateFaceCw(number);
    }
}

void initFaces()
{
    int lastIndex = faceSize - 1;

    faces[0].top = Side(faces + 4, "column", 0);
    faces[0].right = Side(faces + 1, "column", 0);
    faces[0].bottom = Side(faces + 5, "column", 0);
    faces[0].left = Side(faces + 3, "column", lastIndex);

    faces[1].top = Side(faces + 4, "row", lastIndex);
    faces[1].right = Side(faces + 2, "column", 0);
    faces[1].bottom = Side(faces + 5, "row", 0);
    faces[1].left = Side(faces, "column", lastIndex);

    faces[2].top = Side(faces + 4, "column", lastIndex);
    faces[2].right = Side(faces + 3, "column", 0);
    faces[2].bottom = Side(faces + 5, "column", lastIndex);
    faces[2].left = Side(faces + 1, "column", lastIndex);

    faces[3].top = Side(faces + 4, "row", 0);
    faces[3].right = Side(faces, "column", 0);
    faces[3].bottom = Side(faces + 5, "row", lastIndex);
    faces[3].left = Side(faces + 2, "column", lastIndex);

    faces[4].top = Side(faces + 3, "row", 0);
    faces[4].right = Side(faces + 2, "row", 0);
    faces[4].bottom = Side(faces + 1, "row", 0);
    faces[4].left = Side(faces, "row", 0);

    faces[5].top = Side(faces + 1, "row", lastIndex);
    faces[5].right = Side(faces + 2, "row", lastIndex);
    faces[5].bottom = Side(faces + 3, "row", lastIndex);
    faces[5].left = Side(faces, "row", lastIndex);
}

void readTestData()
{
    for (int i = 0; i < faceSize; ++i) {
        for (int j = 0; j < faceSize; ++j) {
            cin >> faces[4](i, j);
        }
    }

    for (int i = 0; i < faceSize; ++i) {
        for (int f = 0; f < 4; ++f) {
            for (int j = 0; j < faceSize; ++j) {
                cin >> faces[f](i, j);
            }
        }
    }

    for (int i = 0; i < faceSize; ++i) {
        for (int j = 0; j < faceSize; ++j) {
            cin >> faces[5](i, j);
        }
    }
}

int main()
{
    int t, r;

    initFaces();

    cin >> t;
    while (t > 0) {
        readTestData();

        cin >> r;
        while (r != 0) {
            if (r > 0) {
                rotateFaceCw(r - 1);
            } else {
                rotateFaceCcw(abs(r) - 1);
            }
            cin >> r;
        }

        auto b = all_of(faces, faces + 6, [](Face &f) -> bool {
            return f.hasOneColor();
        });

        cout << (b ? "YES" : "NO") << endl;
        --t;
    }

    return 0;
}

