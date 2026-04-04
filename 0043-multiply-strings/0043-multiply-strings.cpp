class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();
        if(num1=="0" or num2=="0")return "0";
        vector<int>mul(n+m,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int x=(num1[i]-'0')*(num2[j]-'0');
                mul[i+j+1]+=x;
            }
        }

        int carry=0;
        for(int i=n+m-1;i>=0;i--)
        {
            int sum=carry+mul[i];
            carry=sum/10;
            mul[i]=sum%10;
            cout<<mul[i]<<' ';
        }

        string ans="";
        int i=0;
        for(i;i<mul.size();i++)
        {
            if(mul[i]!=0)break;
        }

        for(i;i<mul.size();i++)
        {
            ans+=(mul[i]+'0');
        }

        return ans;
    }
};