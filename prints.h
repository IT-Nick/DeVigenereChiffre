#pragma once
template <typename It>
int PrintMapRange(It range_begin, It range_end) {
    int counter = 0;
    cout << endl;
    for(auto it = range_begin; it != range_end; ++it) {
        counter++;
        cout << it->first << '/' << it->second << " ";
    }
    cout << endl;
    return counter;
}

template <typename Itm>
int CountOfRange(Itm range_begin, Itm range_end) {
    int counter = 0;
    for(auto it = range_begin; it != range_end; ++it) {
        counter++;
    }
    return counter;
}

int PrintMap(const map<char, int>& m, const string& hint, string alpha) {
    auto x = max_element(m.begin(), m.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) { return p1.second < p2.second; });
    cout << "Max element in " << hint << ": " << x->first << ", matches: " << x->second << endl;
    //auto it = m.find(x->first); //максимальное число
    char das = x->first; //максимальное число
    auto itm = find_if(begin(alpha), end(alpha), [das](char c) {
        if(c != das) {
            return false;
        }
        return true;
    });
    //cout << PrintMapRange(itm, end(alpha)) << endl; //наш сдвиг
    int result = CountOfRange(itm, end(alpha));
    cout << "Your shift in " << hint << " column: " << result << endl; //наш сдвиг
    //int res = m.size() - CountOfRange(itm, end(alpha));
    //int res = m.size() - PrintMapRange(it, end(m));

    for (auto item : m) {
    //    cout << item.first << ": " << item.second << ", "; //вывод количества всех встречающихся букв
    }
    //auto It = std::next(m.begin(), res);
    //cout << endl << endl << endl << It->first << endl << endl << endl;

    for (auto item: m) {
   //     cout << item.first << ": " << item.second << ", ";
    }
    cout << endl;
    return result;
}
