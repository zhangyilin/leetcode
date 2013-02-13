#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class HillHike{
	int dp[101][51][51][2];
public:
	long long paths(bool flag, int currentDistance, int currentHeight, int currentLandmarks, int distance, int maxHeight, vector<int> & landmarks){
		if (flag == true && currentDistance == distance && currentHeight == 0 && currentLandmarks == landmarks.size()){
			return 1;
		}
		else if (currentDistance == distance)
			return 0;
		else if (currentHeight <= 0 && currentDistance != 0)
			return 0;
		else if (currentHeight > maxHeight)
			return 0;
		else if (currentHeight == maxHeight)
			flag = true;
		if (currentLandmarks < landmarks.size() && landmarks[currentLandmarks] == currentHeight)
			currentLandmarks++;
		if (dp[currentDistance][currentHeight][currentLandmarks][flag]>0)//x,y,current landmark,got maxHeight or not
			return dp[currentDistance][currentHeight][currentLandmarks][flag];
		long long ret = 0;
		ret += paths(flag, currentDistance+1, currentHeight+1, currentLandmarks, distance, maxHeight, landmarks);
		ret += paths(flag, currentDistance+1, currentHeight, currentLandmarks, distance, maxHeight, landmarks);
		ret += paths(flag, currentDistance+1, currentHeight-1, currentLandmarks, distance, maxHeight, landmarks);
		dp[currentDistance][currentHeight][currentLandmarks][flag] = ret;
		return ret;
	}
	long long numPaths(int distance, int maxHeight, vector<int> landmarks){
		memset (dp,0,sizeof(dp));
		return paths(false, 0, 0, 0,distance, maxHeight, landmarks);
	}
};

int main(){
	HillHike h;
	int dist = 38;
	int maxH = 11;
	int landm[] = {4,5,8,5,6};
	vector<int> landmarks (landm, landm+sizeof(landm)/sizeof(int) );
	cout<< h.numPaths (dist, maxH, landmarks)<< endl;
}
