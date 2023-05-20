class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        int n=heights.size();
        vector<int> nsr(n,0);
        vector<int> nsl(n,0);

        stack<int> s;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[i]<=heights[s.top()]){
                s.pop();
            }
            if(s.empty()) nsr[i]=n;
            else nsr[i]=s.top();
            s.push(i);
        }

        while(!s.empty()) s.pop();

        for(int i=0;i<n;i++){
            while(!s.empty() && heights[i]<=heights[s.top()]){
                s.pop();
            }
            if(s.empty()) nsl[i]=-1;
            else nsl[i]=s.top();
            s.push(i);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            ans=max(ans, heights[i]*(nsr[i]-nsl[i]-1));
        }
        return ans;        
    }
};
