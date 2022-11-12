#include <bits/stdc++.h>

using namespace std;

vector<int> sumCalculator(vector<vector<int>> s){

    int vectorLine = s.size();
    vector<int> sumCalculator(2*vectorLine + 2,0);
    vector<int> hor(vectorLine,0);
    vector<int> vert(vectorLine,0);
    int normDiag = 0;
    int invDiag = 0;


    for (size_t i=0; i < vectorLine; i++){
        normDiag += s[i][i];
        invDiag += s[i][vectorLine-1-i];

        for (size_t k=0; k < vectorLine; k++){
            hor[k] += s[k][i];
            vert[k] += s[i][k];
        }

    }

    for (size_t idx = 0; idx < vectorLine; idx++){
        sumCalculator[idx] = hor[idx];
        sumCalculator[idx+vectorLine] = vert[idx];
    }

    sumCalculator[2*vectorLine] = normDiag;
    sumCalculator[2*vectorLine+1] = invDiag;

    return sumCalculator;

}

int meanOfVector(vector<int> v){
    int vectorSize = v.size();
    int sumValue = 0;
    for (size_t idx = 0; idx < vectorSize ; idx++){
        sumValue += v[idx];
    }

    double mean = sumValue/vectorSize;

    return int(round(mean));
}

void printVector(vector<int> d){
    size_t vectorSize = d.size();
    for (size_t idx = 0; idx < vectorSize; idx++){
        cout << d[idx] << "\t";
    }
}

void printVoV(vector<vector<int>> d){
    size_t sizeD = d.size();
    for (size_t idx=0; idx < sizeD*sizeD; idx++){
        if ((idx % sizeD) != 0){
            cout << d[floor(idx/sizeD)][idx % sizeD] << "\t";
        }
        else {
            cout << "\n";
            cout << d[floor(idx/sizeD)][idx % sizeD] << "\t";
        }

    }
}

vector<int> varVotes(vector<int> sums){
    int target = meanOfVector(sums);
    int vectorSize = sums.size();
    vector<int> varVotes(vectorSize,0);


    for (size_t idx=0; idx < vectorSize ; idx++){
        varVotes[idx] += abs(sums[idx]-target);
    }

    return varVotes;
}

vector<int> mapVotes(vector<int> varVotes){
    int varSize = varVotes.size();
    int n = (varSize - 2)/2;
    vector<int> votes(n*n,0);

    for (size_t idx = 0; idx < varSize; idx++){
        if (varVotes[idx] != 0){
            if (idx < n){
                for (size_t i = 0; i < n; i++){
                    votes[n*idx+i] += varVotes[idx];
                }
            }
            else if((idx >= n) && (idx < 2*n)){
                for (size_t i = 0; i < n; i++){
                    votes[(idx-n)+n*i] += varVotes[idx];
                }
            }
            else if(idx == 2*n){
                for (size_t i = 0; i < n; i++){
                    votes[(n+1)*i] += varVotes[idx];
                }
            }
            else {
                for (size_t i = 0; i < n; i++){
                    votes[(n-1)*i] += varVotes[idx];
                }
            }
        }
    }
    return votes;
}

int changeElement(vector<int> votes){
    int maxElement = *std::max_element(votes.begin(), votes.end());

    return maxElement;
}

vector<vector<int>> makeChanges(vector<vector<int>> init, vector<int> changes){

    vector<int> initVector = openToVector(init); 
    vector<int> output;
    size_t sizeCh = changes.size();

    for (size_t idx = 0; idx < sizeCh; idx++){
        output[idx] = initVector[idx] + changes[idx];
    }

    vector<vector<int>> fOutput = mergeToVoV(output);
    return fOutput;
}

vector<int> openToVector(vector<vector<int>> s){
    size_t sizeS = s.size();
    vector<int> output(sizeS*sizeS,0);
    for (size_t idx=0; idx < sizeS*sizeS; idx++){
        output[idx] = s[floor(idx/sizeS)][idx % sizeS];
    }

    return output;
}

vector<vector<int>> mergeToVoV(vector<int> s){
    size_t sizeS = sqrt(s.size());
    vector<vector<int>> output;

    for (size_t idx=0; idx< sizeS*sizeS; idx++){
        output[floor(idx/sizeS)][idx % sizeS] = s[idx];
    } 

    return output;

}

int main() 
{

    vector<vector<int>> d = {{5, 3, 4}, {1, 5, 8}, {6, 4, 2}};

    cout << "---The initial square is the following.";
    printVoV(d);
    cout << endl;

    vector<int> res = sumCalculator(d);

    cout << "---The calculated sums are the following." << endl;;
    printVector(res);
    cout << "\n";

    vector<int> varVot = varVotes(res);

    cout << "---The variance in votes is." << endl;
    printVector(varVot);
    cout << "\n";

    vector<int> votes = mapVotes(varVot);

    cout << "---The actual votes are." << endl;;
    printVector(votes);
    cout << "\n";

    int changedElem = changeElement(votes);
    cout << "---The changed element is:    " << changedElem << endl;
    cout << "\n";

    //printVector(outP);

    //printVoV(d);

    //cout << "\n" << changeElement(votes);

    //cout << timeConversion("07:05:45PM");

}
