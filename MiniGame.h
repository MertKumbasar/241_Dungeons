#ifndef MiniGame_H
#define MiniGame_H

#include <iostream>
#include <string>
#include <map>
#include <random>

using namespace std;

class RPC
{
private:
    string *Mrpc{nullptr}, Computer_Name;
    int index;
    int winner1, winner2;

public:
    RPC() : index{3}, Computer_Name{"AI ENEMY"}, winner1{0}, winner2{0}
    {

        Mrpc = new string[index];
        Mrpc[0] = "rock";
        Mrpc[1] = "paper";
        Mrpc[2] = "scissors";
    }

    void GetWinner(string x, string y)
    {

        if (x == "rock")
        {
            if (y == "paper")
                winner2++;
            else if (y == "scissors")
                winner1++;
        }
        else if (x == "paper")
        {

            if (y == "rock")
                winner1++;
            else if (y == "scissors")
                winner2++;
        }
        else if (x == "scissors")
        {

            if (y == "rock")
                winner2++;
            else if (y == "paper")
                winner1++;
        }
    }

    ~RPC()
    {
        delete[] Mrpc;
    }

    void CheckResult()
    {
        int rnd;
        random_device rd;
        string round, computer;

        cout << "Welcome to Rock ,Paper, scissors " << endl;
        cout << "Win 3 round to win!!" << endl;

        do
        {

            mt19937 gen(rd());
            uniform_int_distribution<> dis(0, 2);
            rnd = dis(gen);

            if (Mrpc[rnd] == "rock")
                computer = "rock";

            else if (Mrpc[rnd] == "paper")
                computer = "paper";

            else if (Mrpc[rnd] == "scissors")
                computer = "scissors";

            cout << "Enter Your Choice: " << endl;
            cin >> round;
            cout << Computer_Name << " Generated:" << computer << endl;
            GetWinner(round, computer);

            cout << "Player: " << winner1 << " " << Computer_Name << " " << winner2 << endl
                 << endl;

            if (winner1 == 3)
            {
                cout << "PLAYER WINS" << endl
                     << endl;
                break;
            }

            else if (winner2 == 3)
            {
                cout << Computer_Name << " WINS !!" << endl
                     << endl;
                break;
            }

        } while (true);

        winner1 = 0;
        winner2 = 0;
    }
};

#endif 