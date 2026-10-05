class Solution {
public:
    string simplifyPath(string path) {

        int n = path.size();

        int i=0;
        stack<string>st;
        string temp = "";

        while(i <= n){
            if(i < n && path[i] != '/'){
                temp += path[i];
            }
            else{
                if(temp == "."){
                    
                }
                else if(temp == ".."){
                    if(!st.empty()){
                        st.pop();
                    }
                }
                else if(!temp.empty()){
                    st.push(temp);
                }
                temp = "";
            }

            i++;
        }

        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        if(ans.empty()){
            ans += "/";
        }
        return ans;
        
    }
};