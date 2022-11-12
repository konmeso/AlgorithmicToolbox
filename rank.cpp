#include <bits/stdc++.h>

using namespace std;

vector<int> deleteDuplicate(vector<int> vec){
    set<int> s;
    unsigned size = vec.size();

    for( unsigned i = 0; i < size; ++i ){
        s.insert( vec[i] );
    }

    vec.assign( s.begin(), s.end() );
    return vec;
}

void printVector(vector<int> d){
    size_t vectorSize = d.size();
    for (size_t idx = 0; idx < vectorSize; idx++){
        cout << d[idx] << "\t";
    }
}

vector<int> climbingLadder(vector<int> fRanked, vector<int> scores){
    int totalPositions = fRanked.size() + 1;
    int scoresSize = scores.size();

    vector<int>::iterator bs;
    vector<int>::iterator startingIt=fRanked.begin();

    vector<int> outcome(scoresSize,0);

    for (size_t idx=0; idx < scoresSize; idx++){
        bs = upper_bound(startingIt, fRanked.end(),scores[idx]);
        outcome[idx] = totalPositions - (bs-fRanked.begin());
        startingIt = bs;
    } 

    return outcome;
}

int main(){
    vector<int> ranked = {100,100,50,40,40,20,10};
    vector<int> games = {5,25,50,120};
    int score = 40;

    vector<int> filteredRank = deleteDuplicate(ranked);

    //vector<int> outcome = savePositions(filteredRank,games);
    vector<int> outcome = climbingLadder(filteredRank,games);

    //cout << ranked.size() << endl;
    //cout << findPosition(filteredRank,score,0) <<endl;
    //cout << finalOutcome[0] << endl;

    //cout << "fRanked.begin(): " << *ranked.end() << endl;

    //cout << "The position for the score " << score << " is: " << findPosition(ranked,score,0) << endl;
    cout << "---Filtered Rank" << endl;
    printVector(filteredRank);
    cout << endl;

    cout << "---Scores" << endl;
    printVector(games);
    cout << endl;

    cout << "---Outcome" << endl;
    printVector(outcome);
    cout << endl;

    cout << "---------------------TEST AREA--------------" << endl;
    vector<int> ar = { 2, 3, 4, 5, 15, 25 };
    vector<int>:: iterator testBegin = ar.begin();
    vector<int>:: iterator testEnd = ar.end();
    auto testIt = prev(testEnd,2);
    cout << "Begin Iterator Value: " << *testBegin << endl;
    cout << "End Iterator Value: " << *testEnd << endl;
    cout << "It Iterator Value: " << *testIt << endl;

    vector<int>::iterator lb = lower_bound(ar.begin(),ar.end(),3.4);
    cout << "Lower Bound Value: " << lb-testBegin << endl;

}