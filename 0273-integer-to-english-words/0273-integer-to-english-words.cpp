class Solution {
public:
    unordered_map<int,string> mp;
       
    string helper(string n){
        string res="";
        if(n[0]!='0'){
            res+=mp[n[0]-'0']+" Hundred";
        }
        if(n[1]=='1' && n[2]=='0'){
            int a=(n[1]-'0')*10;
           (res!="") ? res+=" "+mp[a] : res+=mp[a];
        }
        if(n[1]=='1' && n[2]!='0'){
            int a=(n[1]-'0')*10;
            a+=n[2]-'0';
            (res!="") ? res+=" "+mp[a] : res+=mp[a];
        }
        if(n[1]!='0' && n[1]!='1'){
            int a=(n[1]-'0')*10;
            (res!="") ? res+=(" "+mp[a]) : res+=mp[a];
        }
        if(n[2]!='0' && n[1]!='1'){
            (res!="") ? res+=" "+mp[n[2]-'0'] : res+=mp[n[2]-'0'];
        }
        return res;
    }
    string numberToWords(int num) {
        mp[1]="One";
    mp[2]="Two";
    mp[3]="Three";
    mp[4]="Four";
    mp[5]="Five";
    mp[6]="Six";
    mp[7]="Seven";
    mp[8]="Eight";
    mp[9]="Nine";
    mp[10]="Ten";
    mp[11]="Eleven";
    mp[12]="Twelve";
    mp[13]="Thirteen";
    mp[14]="Fourteen";
    mp[15]="Fifteen";
    mp[16]="Sixteen";
    mp[17]="Seventeen";
    mp[18]="Eighteen";
    mp[19]="Nineteen";
    mp[20]="Twenty";
    mp[30]="Thirty";
    mp[40]="Forty";
    mp[50]="Fifty";
    mp[60]="Sixty";
    mp[70]="Seventy";
    mp[80]="Eighty";
    mp[90]="Ninety";
    vector<string> m = {""," Thousand "," Million "," Billion "}; 
        if(num==0) return "Zero";
        string strNum=to_string(num);
        int cnt=0;
        int cnt2=0;
        string res="";
        string temp="";
        for(int i=strNum.size()-1;i>=0;i--){
            temp+=strNum[i];
            cnt++;
            if(cnt==3 || i==0){
                while(cnt!=3){
                    temp+="0";
                    cnt++;
                }
                cnt=0;
                reverse(temp.begin(),temp.end());
                string s=helper(temp);
                if(s!="") res=s+m[cnt2]+res;
                cnt2++;
                temp="";
            }
        }
        res.erase(res.find_last_not_of(" \n\r\t")+1);
        return res;
    }
};