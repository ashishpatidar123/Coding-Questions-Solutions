class Solution {
    int parent[100005];
    int size[100005];

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(size[px] >= size[py]){
            parent[py] = px;
            size[px] += size[py];
        }
        else{
            parent[px] = py;
            size[py] += size[px];
        }
    }
public:
    int largestComponentSize(vector<int>& nums) {
         
        int n = nums.size();
        
        for(int i=0; i<100000; i++){
            parent[i] = i;
            size[i] = 1;
        }

        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         if(find(i) == find(j)){
        //             continue;
        //         }
        //         if(gcd(nums[i], nums[j]) > 1){
        //             unite(i, j);
        //         }
        //     }
            
        // }
        // int ans = 0;
        // for(int i=0; i<n; i++){
        //     ans = max(ans, size[i]);
        // }

        // return ans;

        for(int i=0; i<n; i++){
            int num = nums[i];
            // instead checking for each pair, we will 
            // check the factors of that number and unite all
            for(int j=2; j*j <= num; j++){
                if(num % j == 0){
                    unite(num, j);
                    unite(num, num / j);
                }
            }
        }

        unordered_map<int, int>count;

        int ans = 0;
        for(int i=0; i<n; i++){
            // calculating the count of the numbers sharing the same root
            int root = find(nums[i]);
            count[root]++;
            ans = max(ans, count[root]);
        }
        return ans;
    }
};