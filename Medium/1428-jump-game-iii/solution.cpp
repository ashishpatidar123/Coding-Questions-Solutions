class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n =  arr.size();
        queue<int>q;
        q.push(start);
        vector<bool>visited(n, false);
        visited[start] = true;
        while(!q.empty()){

            int size = q.size();

            for(int i=0; i<size; i++){
                int index = q.front();
                q.pop();

                if(arr[index] == 0){
                    return true;
                }
                int first = index + arr[index];

                if(first < n && !visited[first]){
                    q.push(first);
                    visited[first] = true;
                }

                first = index - arr[index];

                if(first >=0 && !visited[first]){
                    q.push(first);
                    visited[first] = true;
                }
            }

        }

        return false;
    }
};
