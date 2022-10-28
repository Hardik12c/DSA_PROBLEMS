class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // making a vector of the map where i will store the count of every char of every string in the vector
        vector<unordered_map<char,int>> vmpp(strs.size());
        
        // mapping every character value
        for(int i=0;i<strs.size();i++){
            string k=strs[i];
            for(int j=0;j<k.length();j++){
                vmpp[i][k[j]]++;
            }
        } 
        // making a bool vector to get info that we have stored that string or not
        vector<bool> v(strs.size(),true);
        
        // ans vector
        vector<vector<string>> ans;
        
        // now iterating over the complete vector
        for(int i=0;i<strs.size();i++){
            
            // making another string vector to store the values which are anagrams
            vector<string> store;
            
            // taking ith string from the vector
            string k=strs[i];
            
            // checking we have pushed it into the ans or not
            if(v[i]){
                store.push_back(k);
                v[i]=false;
            }else continue;     //if pushed then we are going to next loop
            
            
            // now iterating over all the string after ith string 
            for(int j=i+1;j<strs.size();j++){
                if(v[j]==true && vmpp[i]==vmpp[j]){  //checking whether the string didn't get pushed and it is an anagram of ith string if yes then
                    store.push_back(strs[j]);         //push it into store
                    v[j]=false;                     //making it to false
                }
            }
            ans.push_back(store);               // pushing it into answer
        }
        return ans;
    }
};