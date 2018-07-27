/**
 * This program does not give accepted results.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

const int FACE_SIZE = 3;

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
    char content[FACE_SIZE][FACE_SIZE];
    Side top, left, bottom, right;

    Face(): top(), left(), bottom(), right() {}

    void readFromStdin() {
        for (int i = 0; i < FACE_SIZE; ++i) {
            for (int j = 0; j < FACE_SIZE; ++j) {
                cin >> content[i][j];
            }
        }
    }

    void print() {
        for (int i = 0; i < FACE_SIZE; ++i) {
            for (int j = 0; j < FACE_SIZE; ++j) {
                cout << content[i][j] << " ";
            }
        }
        cout << endl;
    }

    bool hasOneColor() {
        for (int i = 0; i < FACE_SIZE; ++i) {
            for (int j = 0; j < FACE_SIZE; ++j) {
                if (content[i][j] != content[0][0]) {
                    return false;
                }
            }
        }
        return true;
    }

    char &operator()(const int &i, const int &j) {
        return content[i][j];
    }

    void setColumn(int col, const vector<char> &v) {
        for (int j = 0; j < FACE_SIZE; ++j) {
            content[j][col] = v[j];
        }
    }

    vector<char> getColumn(int col) {
        vector<char> v;
        for (int j = 0; j < FACE_SIZE; ++j) {
             v.push_back(content[j][col]);
        }
        return v;
    }

    void setRow(int row, const vector<char> &v) {
        for (int j = 0; j < FACE_SIZE; ++j) {
            content[row][j] = v[j];
        }
    }

    vector<char> getRow(int row) {
        vector<char> v;
        for (int j = 0; j < FACE_SIZE; ++j) {
             v.push_back(content[row][j]);
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
        return getColumn(FACE_SIZE - 1);
    }

    void setRightColumn(const vector<char> &v) {
        setColumn(FACE_SIZE - 1, v);
    }

    vector<char> getTopRow() {
        return getRow(0);
    }

    void setTopRow(const vector<char> &v) {
        setRow(0, v);
    }

    vector<char> getBottomRow() {
        return getRow(FACE_SIZE - 1);
    }

    void setBottomRow(const vector<char> &v) {
        setRow(FACE_SIZE - 1, v);
    }

    void rotateCw() {
        auto rightColumn = getRightColumn();
        auto leftColumn = getLeftColumn();
        auto bottomRow = getBottomRow();
        auto topRow = getTopRow();

        setRightColumn(topRow);

        reverse(rightColumn.begin(), rightColumn.end());
        setBottomRow(rightColumn);
        
        setLeftColumn(bottomRow);

        reverse(leftColumn.begin(), leftColumn.end());
        setTopRow(leftColumn);

        auto topContent = top.getContent();
        auto bottomContent = bottom.getContent();
        auto leftContent = left.getContent();
        auto rightContent = right.getContent();

        right.setContent(topContent);

        reverse(rightContent.begin(), rightContent.end());
        bottom.setContent(rightContent);
        
        left.setContent(bottomContent);
        
        reverse(leftContent.begin(), leftContent.end());
        top.setContent(leftContent);
    }

    void rotateCcw() {
        for (int j = 0; j < 3; ++j) {
            rotateCw();
        }
    }

    // void rotateCcw() {
    //     auto rightColumn = getRightColumn();
    //     auto leftColumn = getLeftColumn();
    //     auto bottomRow = getBottomRow();
    //     auto topRow = getTopRow();

    //     reverse(topRow.begin(), topRow.end());
    //     setLeftColumn(topRow);

    //     setBottomRow(leftColumn);

    //     reverse(bottomRow.begin(), bottomRow.end());
    //     setRightColumn(bottomRow);

    //     setTopRow(rightColumn);

    //     auto topContent = top.getContent();
    //     auto bottomContent = bottom.getContent();
    //     auto leftContent = left.getContent();
    //     auto rightContent = right.getContent();

    //     reverse(topContent.begin(), topContent.end());
    //     left.setContent(topContent);

    //     bottom.setContent(leftContent);

    //     reverse(bottomContent.begin(), bottomContent.end());
    //     right.setContent(bottomContent);

    //     top.setContent(rightContent);
    // }
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
    for (int j = 0; j < FACE_SIZE; ++j) {
        auto ch = (*face)(type == "row" ? index : j, type == "row" ? j : index);
        v.push_back(ch);
    }
    return v;
}

void Side::setContent(const vector<char> &v) {
    for (int j = 0; j < FACE_SIZE; ++j) {
        (*face)(type == "row" ? index : j, type == "row" ? j : index) = v[j];
    }
}

Face faces[6];

void initFaces()
{
    int lastIndex = FACE_SIZE - 1;

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
    for (int j = 0; j < 3; ++j) {
            cin >> faces[4](j, 0) >> faces[4](j, 1) >> faces[4](j, 2);
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> faces[j](i, 0) >> faces[j](i, 1) >> faces[j](i, 2);
        }
    }
    for (int j = 0; j < 3; ++j) {
        cin >> faces[5](j, 0) >> faces[5](j, 1) >> faces[5](j, 2);
    }
}

#define DEBUG 1

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
                faces[r-1].rotateCw();
            } else {
                faces[abs(r)-1].rotateCcw();
            }
            cin >> r;
        }

        auto b = all_of(faces, faces + 6, [](Face &f) -> bool {
            return f.hasOneColor();
        });

#ifdef DEBUG
        for (int j = 0; j < 6; ++j) {
            faces[j].print();
        }
#endif

        cout << (b ? "YES" : "NO") << endl;

        --t;
    }

    return 0;
}

