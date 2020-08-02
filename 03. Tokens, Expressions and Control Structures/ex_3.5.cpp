/*
 * Problem:
 *  Count no. of votes for each candidate marked on
 *  a ballot paper. Also count the spoilt ballot.
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <ctime>

void countVotesAndSpoiltBallot(std::vector<int>, std::vector<int> &, int &);

int main()
{
    int spoiltBallot = 0;

    const int numOfVoters = 15;
    const int numOfCandidates = 5;

    std::vector<int> candidates;
    std::vector<int> ballotPaper;
    candidates.resize(numOfCandidates);
    ballotPaper.resize(numOfVoters);

    /* Initialize the dataset with random values
     * between 1 to 5 */
    srand(time(NULL));
    for (auto i = 0; i < numOfVoters; i++)
        ballotPaper[i] = int(rand() % 6 + 1);

    countVotesAndSpoiltBallot(ballotPaper, candidates, spoiltBallot);

    std::cout << std::setw(10) << "candidates"
              << std::setw(8) << "votes" << std::endl;
    int i = 1;
    for (auto it = candidates.begin(); it != candidates.end(); it++, i++)
        std::cout << std::setw(5) << i << std::setw(12) << *it << std::endl;
    std::cout << "spoilt ballot = " << spoiltBallot << std::endl;

    return EXIT_SUCCESS;
}

void countVotesAndSpoiltBallot(std::vector<int> votes, std::vector<int> &candidates, int &spoiltBallot)
{
    const int size = votes.size();
    for (auto i = 0; i < size; i++)
    {
        if (votes[i] >= 1 && votes[i] <= 5)
            candidates[votes[i] - 1] += 1;
        else
            spoiltBallot += 1;
    }
}