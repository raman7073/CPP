#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, f, a, b;
        cin >> n >> f >> a >> b;

        vector<long long> moments(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> moments[i];
        }

        bool canSendAllMessages = true;
        long long currentCharge = f;

        for (int i = 0; i < n; ++i)
        {
            long long timeToNextMessage = (i == 0) ? moments[i] : moments[i] - moments[i - 1];
            long long chargeLoseWhileOn = timeToNextMessage * a;
            long long chargeLossForSwitchON = b;
            if (chargeLoseWhileOn > chargeLossForSwitchON)
            {
                currentCharge -= chargeLossForSwitchON;
                if (currentCharge <= 0)
                {
                    canSendAllMessages = false;
                    break;
                }
            }
            else
            {
                currentCharge -= chargeLoseWhileOn;
                if (currentCharge <= 0)
                {
                    canSendAllMessages = false;
                    break;
                }
            }
            //cout<<currentCharge<<endl;
        }

        cout << (canSendAllMessages ? "YES" : "NO") << endl;
    }

    return 0;
}
