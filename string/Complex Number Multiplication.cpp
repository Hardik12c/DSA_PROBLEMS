class Solution {
public:
    void makenumber(int &real,int &image,string num1){
        int a=0;
        bool flag=true;
        bool imgcheck=false;
        for(int i=0;i<num1.length();i++){
            if(isdigit(num1[i])){
                int k=num1[i]-'0';
                if(flag==true){
                    real=(real*(pow(10,a)))+k;
                }else{
                    image=(image*(pow(10,a)))+k;
                }
                a++;
            }
            if(num1[i]=='+'){
                if(num1[i+1]=='-'){
                    imgcheck=true;
                }
                a=0;
                flag=false;
            }
        }
        if(num1[0]=='-') real=0-real;
        if(imgcheck) image=0-image; 
    }
    string complexNumberMultiply(string num1, string num2) {
        int real1=0;
        int image1=0;
        int real2=0;
        int image2=0;
        makenumber(real1,image1,num1);
        makenumber(real2,image2,num2);

        string real=to_string((real1*real2)-(image1*image2));
        string image=(to_string((image1*real2)+(real1*image2)))+'i';

        return real+'+'+image;
        // return
    }
};