#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number of persons" << endl;
    cin >> n;
    cout << endl;
    vector<string> v;

    int index = 0;
    while (n--)
    {
        cout << "Enter First Name of " << ++index << endl;
        string s;
        cin >> s;
        cout << endl;
        v.push_back(s);
    }
    n = index;

    vector<vector<float>> exp(n, vector<float>(n, 0));

    int tamount = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Total amount payed by " << v[i] << endl;
        int amtpayed;
        cin >> amtpayed;
        cout << endl;
        tamount += amtpayed;

        if (amtpayed == 0) // agar bill pay nahi kar raha hai
        {
            continue;
        }

        else // apne alava kisi or ka bhi bill de sakta hai
        {

            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    cout << j << ". " << v[j] << endl;
                }
            }
            vector<pair<int, int>> temp;

            int x = 0;
            int tempnum = n;
            tempnum--;
            while (tempnum--) // input lene ke liye
            {
                cout << "Enter Number associated for the person payed for, -1 if not payed for anyone" << endl;
                cin >> x;

                if (x == -1)
                    break;

                cout << "Enter amount payed for " << v[x] << endl;
                int a;
                cin >> a;
                temp.push_back({x, a});
                amtpayed -= a;
            }
            temp.push_back({i, amtpayed});

            for (auto it : temp)
            {
                exp[i][it.first] = it.second;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << exp[i][j] << " ";
        }
        cout << endl;
    }

    tamount /= n;

    // matrix ban gayi par ab calculate mon own kar raha hai or kon debt me hai

    // agar apna diya hoga to own 0 karega
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        int owe = tamount - exp[i][i];
        int get = 0;
        vector<pair<int, int>> toget;
        vector<pair<int, int>> towe;

        if (exp[i][i] >= tamount)
        {
            owe = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j && exp[i][j] != 0)
                {
                    get += exp[i][j];
                    toget.push_back({exp[i][j], j});
                }
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && exp[j][i] != 0)
                {
                    towe.push_back({exp[j][i], j});
                }
            }
        }
        // int toown;
        // for (int j = 0; j < n; j++)
        // {
        //     if (exp[j][i] != 0)
        //     {
        //         toown = j;
        //         break;
        //     }
        // }

        if (owe == 0 && get == 0)
        {
            cout << v[i] << " Has cleared bill " << endl;
        }
        else if (owe == 0 && get != 0)
        {
            cout << v[i] << " Will get money from " << endl;
            for (auto it : toget)
            {
                cout << v[it.second] << " Amount " << it.first << endl;
            }
        }
        else
        {
            cout << v[i] << " Owes "<< endl;
            // cout << v[i] << " Owes " << v[toown] << " Amount " << tamount - exp[i][i] << endl;

            for (auto it : towe)
            {
                cout << v[it.second] << " Amount " << it.first << endl;
            }
        }
        cout << endl;
        cout << endl;
    }
}

// 4 Natesh Varun Shivansh Piyush 230 2 30 3 100 -1 100 -1 70 -1 0
// 4 Natesh Varun Shivansh Piyush 115 2 15 -1 100 -1 80 -1 105 2 5 -1
