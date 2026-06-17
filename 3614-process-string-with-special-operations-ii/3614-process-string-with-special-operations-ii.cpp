class Solution {
public:
    char processStr(string s, long long k) {
       long long len=0;
        for(auto x: s)
        {
           if(x=='*')
           {
                if(len>0)
                    len--;

           }else if(x=='%')
           {
                continue;

           }else if(x=='#')
           {
              len+=len;
           }else
           {
              len++;
           }
        }
    //    a.  aa. aab. baa 
        // cout<<len<<endl;

        if(k+1>len)
        {
            return '.';
        }

        reverse(s.begin(),s.end());
        for(auto x: s)
        {
           if(x=='*')
           {
                len++;

           }else if(x=='%')
           {
                k=len-1-k;
                
           }else if(x=='#')
           {
              if(k+1>(len+1)/2)
              {
                k=k-(len+1)/2;
              }
              len=(len+1)/2;
           }else
           {
              if(k+1==len)
              {
                  return x;
              }
              len--;
           }

        //    cout<<len<<' '<<k<<endl;
        }
        return '.';

    }
};

