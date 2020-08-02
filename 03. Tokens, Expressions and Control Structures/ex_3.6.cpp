#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

const int count = 3;

void calcBattingAverage(std::vector<std::string>, std::vector<int>, std::vector<int>, std::vector<int>, std::vector<float> &);
void initDataset(std::vector<std::string> &, std::vector<int> &, std::vector<int> &, std::vector<int> &);
void printTableWithAverageScore(std::vector<std::string>, std::vector<int>, std::vector<int>, std::vector<int>, std::vector<float>);

int main()
{
    std::vector<std::string> players;
    std::vector<int> runsScored;
    std::vector<int> innings;
    std::vector<int> timesNotOut;
    std::vector<float> average;

    initDataset(players, runsScored, innings, timesNotOut);
    calcBattingAverage(players, runsScored, innings, timesNotOut, average);
    printTableWithAverageScore(players, runsScored, innings, timesNotOut, average);

    return EXIT_SUCCESS;
}

void calcBattingAverage(std::vector<std::string> players, std::vector<int> runsScored, std::vector<int> innings, std::vector<int> timesNotOut, std::vector<float> &average)
{
    for (auto i = 0; i < count; i++)
    {
        float avg = runsScored[i] / float(innings[i] - timesNotOut[i]);
        average.push_back(avg);
    }
}

void initDataset(std::vector<std::string> &players, std::vector<int> &runsScored, std::vector<int> &innings, std::vector<int> &timesNotOut)
{
    players.push_back("Sachin");
    players.push_back("Saurav");
    players.push_back("Rahul");

    runsScored.push_back(8430);
    runsScored.push_back(4200);
    runsScored.push_back(3350);

    innings.push_back(230);
    innings.push_back(130);
    innings.push_back(105);

    timesNotOut.push_back(18);
    timesNotOut.push_back(9);
    timesNotOut.push_back(11);
}

void printTableWithAverageScore(std::vector<std::string> players, std::vector<int> runsScored, std::vector<int> innings, std::vector<int> timesNotOut, std::vector<float> average)
{
    std::cout << std::setw(20) << "Player's name"
              << std::setw(10) << "Runs"
              << std::setw(10) << "Innings"
              << std::setw(20) << "Times not out"
              << std::setw(10) << "Average" << std::endl;
    for (auto i = 0; i < count; i++)
    {
        std::cout << std::setw(20) << players[i]
                  << std::setw(10) << runsScored[i]
                  << std::setw(10) << innings[i]
                  << std::setw(20) << timesNotOut[i]
                  << std::setw(10) << std::setprecision(4) << average[i]
                  << std::endl;
    }
}