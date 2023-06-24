#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() 
{
    int NumberofVotes;
    cout << "Kindly Enter the number of votes: " << endl;
    cin >> NumberofVotes;
    cin.ignore();

    map<string, int> votes;

    cout << "Kindly enter movie name to resemble each vote one to a line. " << endl;
    for (int i = 0; i < NumberofVotes; i++) {
        string movieName;
        getline(cin, movieName);
        votes[movieName]++;
    }

    int maxVotes = 0;
    string bestMovie;

    for (auto vote : votes) {
        if (vote.second > maxVotes) {
            maxVotes = vote.second;
            bestMovie = vote.first;
        }
    }

    cout << "The best movie is " << bestMovie << " with " << maxVotes << " votes." << endl;
    return 0;
}

