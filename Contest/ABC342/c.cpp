#include <iostream>
#include <string>

int main()
{
    using namespace std;
    unsigned N;
    cin >> N;
    string S;
    cin >> S;

    unsigned Q;
    cin >> Q;
    string from, to;
    from = to = "abcdefghijklmnopqrstuvwxyz"s;

    for (unsigned i = 0; i < Q; ++i)
    {
        char c, d;
        cin >> c >> d;
        for (auto &&m : to)
            if (m == c)
                m = d;
    }

    for (const auto c : S)
        for (unsigned i = 0; i < 26; ++i)
            if (c == from[i])  // 変換前の文字から
                cout << to[i]; // 変換後の文字を求める
    cout << endl;

    return 0;
}
