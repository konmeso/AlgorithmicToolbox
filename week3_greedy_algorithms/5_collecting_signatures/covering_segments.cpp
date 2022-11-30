#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <bits/stdc++.h>

using std::vector;
using namespace std;

struct Segment {
  int start, end;
};

vector<int> scoring(vector<int> activeIdxs, vector<int> uniquePoints, vector<Segment> &segments){
  size_t sizeUniquePoints = uniquePoints.size();
  size_t sizeIdxs = activeIdxs.size();

  vector<int> scoring(sizeUniquePoints,0);

  for (size_t i = 0; i < sizeUniquePoints ; i++){
    for (int ii : activeIdxs){
      if ((uniquePoints[i] >= segments[ii].start) && (uniquePoints[i] <= segments[ii].end)){
        scoring[i]++;
      }
      cout << "Score " << i << "-> " << scoring[i] << endl;
    }
  }

  return scoring;
}

vector<int> cutPoints(vector<int> scoring, vector<int> uniquePoints, vector<int> cutPoints){
  
  int elementCut = *max_element(scoring.begin(), scoring.end());
  cutPoints.push_back(uniquePoints[elementCut]);
  return cutPoints;

}

vector<int> activeIndexes(vector<int> activeIdxs, vector<int> cutPoints, vector<Segment> segments){
  
  for (int ii : activeIdxs){
    if ((cutPoints.back() >= segments[ii].start) && (cutPoints.back() <= segments[ii].end)){
      activeIdxs.erase(find(activeIdxs.begin(),activeIdxs.end(),ii));
    }
  }

  return activeIdxs;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  vector<int> cuttingPoints;
  
  // Insert all endpoints
  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }

  // Keep only unique points
  set<int> s;
  unsigned size = points.size();
  for( unsigned i = 0; i < size; ++i ){
    s.insert( points[i] );
  } 

  points.assign( s.begin(), s.end() );

  // Create vector with active indexes of segments
  vector<int> activeIdxs(segments.size());
  iota(activeIdxs.begin(), activeIdxs.end(),0);

  // Initialize cutting points
  vector<int> cuttingPoints;

  cout << activeIdxs.size();

  while(!activeIdxs.empty()){
    vector<int> scoringBoard = scoring(activeIdxs,points,segments);
    vector<int> cuttingPoints = cutPoints(scoringBoard,points,cuttingPoints);
    activeIdxs = activeIndexes(activeIdxs,cuttingPoints,segments);
  }

  return cuttingPoints;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  
  std::cout << "Print this";

  //vector<int> points = optimal_points(segments);

  //std::cout << points.size() << "\n";
  //for (size_t i = 0; i < points.size(); ++i) {
    //std::cout << points[i] << " ";
  //}
}
