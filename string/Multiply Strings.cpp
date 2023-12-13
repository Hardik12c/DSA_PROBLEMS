class Solution {
public:
string addTwoNumbers(string a,string b){
    string ans="";
    int n=a.length()-1;
    int m=b.length()-1;
    int carry=0;
    while(n>=0 && m>=0){
        int num1=a[n]-'0';
        int num2=b[m]-'0';
        int sum=(num1+num2+carry);
        ans.push_back((sum%10)+'0');
        carry=sum/10;
        n--;m--;
    }
    while(n>=0){
        int num=a[n]-'0';
        int sum=num+carry;
        ans.push_back((sum%10)+'0');
        carry=sum/10;
        n--;
    }
    while(m>=0){
        int num=b[m]-'0';
        int sum=num+carry;
        ans.push_back((sum%10)+'0');
        carry=sum/10;
        m--;
    }
    while(carry>0){
        ans.push_back((carry%10)+'0');
        carry/=10;
    }
     reverse(ans.begin(),ans.end());
     return ans;
}
    string multiply(string num1, string num2) {
        string ans="";
        for(int i=num2.length()-1;i>=0;i--){
            int k=num2[i]-'0';
            int carry=0;
            string total="";
            for(int j=num1.length()-1;j>=0;j--){
                    int l=num1[j]-'0';
                    int mul=(k*l)+carry;
                    total+=(mul%10)+'0';
                    carry=mul/10;
            }
            while(carry>0){
                total+=(carry%10)+'0';
                carry/=10;
            }
            reverse(total.begin(),total.end());
            for(int j=i;j<num2.length()-1;j++){
                total+='0';
            }
            ans=addTwoNumbers(ans,total);
        }
        for(int i=0;i<ans.length();i++){
            if(ans[i]!='0') return ans;
        }
        return "0";
    }
};