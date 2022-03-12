#pragma once
map<char, int> BuildCharZero(const Matrix& m) {
    map<char, int> counters;
    for (int j = 0; j < m.GetNumRows(); j++) {
        ++counters[m.At(j, 0)];
    }
    return counters;
}

map<char, int> BuildCharOne(const Matrix& m) {
    map<char, int> counters;
    for (int j = 0; j < m.GetNumRows(); j++) {
        ++counters[m.At(j, 1)];
    }
    return counters;
}

map<char, int> BuildCharTwo(const Matrix& m) {
    map<char, int> counters;
    for (int j = 0; j < m.GetNumRows(); j++) {
        ++counters[m.At(j, 2)];
    }
    return counters;
}

map<char, int> BuildCharThree(const Matrix& m) {
    map<char, int> counters;
    for (int j = 0; j < m.GetNumRows(); j++) {
        ++counters[m.At(j, 3)];
    }
    return counters;

}
