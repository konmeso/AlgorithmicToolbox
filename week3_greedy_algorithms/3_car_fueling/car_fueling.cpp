#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

using namespace std;

size_t idxStart;

int nextStop(int position, int dist, int tank, vector<int> s){

    int tankPos = position + tank;
    size_t sizeS = s.size();
    size_t tempIdx = idxStart;

    while((tankPos >= s[idxStart]) && (idxStart < sizeS)){
        idxStart++;
    }

    if(tankPos >= dist){
        return dist;
    }
    else if (tempIdx < idxStart){
        return s[idxStart-1];
    }
    else{
        return -1;
    }

}

int compute_min_refills(int dist, int tank, vector<int> & stops) {

    int pos = 0;
    int n = 0;

    size_t idxStart = 0;

    while (pos < dist){
        pos = nextStop(pos, dist, tank, stops);
        //cout << "Position: " << pos << endl;
        if (pos != -1){
            n++;
        }
        else{
            return -1;
        }
    } 

    return n-1;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
