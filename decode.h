string DeVIGENERE(string messange, string key)
{
    int position = 1;
    string decodirovka;
    vector<int> skey;
    for (auto i : key)
    {
        skey.push_back(i - 128);
    }
    for (auto i : messange)
    {
        if (position > skey.size()) position = 1;
        if (i - skey[position] >= 128) decodirovka += i - skey[position] + 6;
        else decodirovka += 159 - skey[position] + (i - 128) + 2;
    }
    return decodirovka;
}
