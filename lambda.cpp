#include <bits/stdc++.h>

// Voidaan integroida funktio parametriksi
bool onko_parillinen(int x)
{
    return x % 2 == 0;
}

// Kas nain
void etsi_parillinen(std::vector<int>& v)
{
    auto paikka = std::find_if(v.begin(), v.end(), [](int x) {return x % 2 == 0;});
}