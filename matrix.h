#pragma once

#include <sstream>

class Matrix {
private:
    int num_rows_;
    int num_columns_;
    string msg_;

    vector<vector<char>> elements_;

public:
    Matrix() {
        num_rows_ = 0;
        num_columns_ = 0;
        msg_ = "NONE";
    }

    Matrix(int num_rows, int num_columns, string& msg) {
        msg_ = msg;
        Reset(num_rows, num_columns);
    }

    void Reset(int num_rows, int num_columns) {
        if (num_rows < 0) {
            throw out_of_range("num_rows must be >= 0");
        }
        if (num_columns < 0) {
            throw out_of_range("num_columns must be >= 0");
        }
        if (num_rows == 0 || num_columns == 0) {
            num_rows = num_columns = 0;
        }

        num_rows_ = num_rows;
        num_columns_ = num_columns;
        elements_.assign(num_rows, vector<char>(num_columns));
    }

    char& At(int row, int column) {
        return elements_.at(row).at(column);
    }

    char At(int row, int column) const {
        return elements_.at(row).at(column);
    }

    int GetNumRows() const {
        return num_rows_;
    }

    int GetNumColumns() const {
        return num_columns_;
    }
    string GetMsg() const {
        return msg_;
    }
};

istream& operator>>(istream& in, Matrix& matrix) {
    int num_rows = matrix.GetNumRows();
    int num_columns = matrix.GetNumColumns();
    //in >> num_rows >> num_columns;
    stringstream ss;
    matrix.Reset(num_rows, num_columns);
    ss << matrix.GetMsg();
    for (int row = 0; row < num_rows; ++row) {
        for (int column = 0; column < num_columns; ++column) {
            ss >> matrix.At(row, column);
        }
    }

    return in;
}

ostream& operator<<(ostream& out, const Matrix& matrix) {
    out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
    for (int row = 0; row < matrix.GetNumRows(); ++row) {
        for (int column = 0; column < matrix.GetNumColumns(); ++column) {
            if (column > 0) {
                out << " ";
            }
            out << matrix.At(row, column);
        }
        out << endl;
    }

    return out;
}