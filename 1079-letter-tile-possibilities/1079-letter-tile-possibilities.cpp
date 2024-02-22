class Solution {
public:
void solve2(string s, int i,int &cnt)
{
    cnt++;
    for(int idx=i;idx<s.size();idx++){
        if(idx!=i && s[idx]==s[i]) continue;
        swap(s[idx],s[i]);
        solve2(s,i+1,cnt);
    }
}
    int numTilePossibilities(string tiles) {
        int cnt=-1;
        sort(tiles.begin(),tiles.end());
        solve2(tiles,0,cnt);
        return cnt;
    }
};