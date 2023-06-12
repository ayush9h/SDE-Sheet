class Solution {
public:
    unordered_set<string> set;
    void sol(int i, string s, string temp,int dot)
    {
        if(i>=s.size())
        {
            if(dot==4)
            {
                temp.pop_back();
                set.insert(temp);
            }
            return;
        }
        if(dot>=4) return;
        sol(i+1,s,temp+s.substr(i,1)+'.',dot+1);
        if(s[i] != '0') sol(i+2,s,temp+s.substr(i,2)+'.',dot+1);
        if(s[i] !='0' && stoi(s.substr(i,3))<=255)
            sol(i+3,s,temp+s.substr(i,3)+'.',dot+1);

    }
    vector<string> restoreIpAddresses(string s) {
        sol(0,s,"",0);
        vector<string> ans(set.begin(),set.end());
        return ans;
    }
};
