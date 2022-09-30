class Solution {
public:
int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(),heaters.end());
    heaters.push_back(INT_MAX);
    int ans=0;
    for(int i=0;i<houses.size();++i){
        int hopos=houses[i];
        int low=0,high=heaters.size()-1,ld=INT_MAX,rd=INT_MAX;
        while(low <= high){
            int mid=(low+high)/2;
            if(heaters[mid] == hopos){
                ld=0;rd=0;
                break;
            } else if(hopos < heaters[mid]){
                rd=heaters[mid]-hopos;
                high=mid-1;
            } else { 
                ld=hopos-heaters[mid];
                low=mid+1;
            }
        }
        ans=max(ans,min(ld,rd));
    }
    return ans;
}
};

// qsn link:
// https://leetcode.com/problems/heaters/