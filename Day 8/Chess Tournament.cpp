bool isPossible(vector<int> &positions, int c, int mid) {
    
    int playerCount = 1;
    int lastRoom = positions[0];
    
    for(int i = 0; i < positions.size(); i++) {
        if(positions[i]-lastRoom >= mid) {
            playerCount = playerCount + 1;
            if (playerCount == c) {
                return true;
            }
            lastRoom = positions[i];
        }
    }
    return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	
	sort(positions.begin(), positions.end());
    int s = 0;
    int maxi = -1;
    for(int i = 0; i < positions.size(); i++) {
        maxi = max(maxi, positions[i]);
    }
    int e = maxi;
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e) {
    if (isPossible(positions, c, mid)) {
        ans = mid;
        s = mid + 1;
    }
        else{
            e = mid - 1;
        }
        mid = s + (e-s)/2;
  }
    return ans;
}
