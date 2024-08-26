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

    cout << "Enter number total number of occasions which required payments: " << endl;
    int countvis;
    cin >> countvis;
    cout << endl;
    vector<vector<vector<float>>> visitedplustable;
    vector<string> visited;

    for (int i = 0; i < countvis; i++)
    {
        string s;
        cout << "Enter Occasion " << i + 1 <<"."<< endl;
        cin >> s;
        cout << endl;
        visited.push_back(s);
    }

    int tamount = 0;

    for (int i = 0; i < countvis; i++)
    {
        cout << "Enter the payment details for " << visited[i] << endl;
        for (int j = 0; j < n; j++)
        {
            cout << "Enter Total amount payed by " << v[j] << endl;
            int amtpayed;
            cin >> amtpayed;
            cout << endl;
            tamount += amtpayed;
            vector<vector<float>> exp(n, vector<float>(n, 0));
            if (amtpayed == 0) // agar bill pay nahi kar raha hai
            {
                continue;
            }
            else // apne alava kisi or ka bhi bill de sakta hai
            {

                for (int k = 0; k < n; k++)
                {
                    if (j != k)
                    {
                        cout << k << ". " << v[k] << endl;
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
                temp.push_back({j, amtpayed});

                for (auto it : temp)
                {
                    exp[j][it.first] = it.second;
                }
            }
            visitedplustable.push_back(exp);
        }
    }
    for (int i = 0; i < countvis; i++)
    {
        cout << "Expenses for Occasion :" << visited[i] << endl;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << visitedplustable[i][j][k] << " ";
            }
            cout << endl;
        }
    }
    cout << tamount;

    vector<vector<float>> finalmatrix(n, vector<float>(n, 0));

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         for (int k = 0; k < n; k++) {
    //             finalmatrix[j][k] += visitedplustable[i][j][k];
    //         }
    //     }
    // }


    // cout<<endl;
    cout<<endl;
    cout<<endl;
    // cout<<endl;
    // cout<<endl;
    // cout<<endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << finalmatrix[i][j] << " ";
        }
        cout << endl;
    }



    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;



    tamount /= n;
    cout << endl;

    // cout<<tamount;
    
    // 2 Nitin Mummy 2 Taxi Flight 400 1 200 0 0 6000 0 3000
    // 3 Nitin Papa Mummy 3 Taxi Flight Rail 1200 1 400 2 400 0 0 0 1800 0 600 2 600 0 0 0 9000 0 3000 1 3000


     vector<int> net_balance(n, 0);

    // Calculate the net balance for each person
    for (int i = 0; i < n; i++) {
        int paid = 0, received = 0;
        for (int j = 0; j < n; j++) {
            paid +=finalmatrix[i][j];      // Total paid by person i
            received +=finalmatrix[j][i];  // Total received by person i
        }
        net_balance[i] = received - paid;
    }

    // Output who owes or is owed money
    cout << "\nBalances:\n";
    for (int i = 0; i < n; i++) {
        if (net_balance[i] > 0) {
            cout  << v[i] << " is owed " << net_balance[i] << " units.\n";
        } else if (net_balance[i] < 0) {
            cout << v[i] << " owes " << -net_balance[i] << " units.\n";
        } else {
            cout << v[i] << " has no net balance.\n";
        }
    }

    return 0;

}


// // 4 Natesh Varun Shivansh Piyush 230 2 30 3 100 -1 100 -1 70 -1 0
// // 4 Natesh Varun Shivansh Piyush 115 2 15 -1 100 -1 80 -1 105 2 5 -1
