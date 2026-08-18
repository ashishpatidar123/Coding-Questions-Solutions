class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // initialise two pointers 
        // one starting from start(0)
        // and other from the end(n-1)
        int start=0;
        int end=height.size()-1;
        // create a variable area to store the area of the container formed by the lines
        // start and end
        long long int area = 0;
        // define max area as 0
        int max_area = 0;
        // run the loop until both pointers meet
        while(start<end){
            
            // find the minimum of the two heights
            // that is - starting vertical line and ending vertical line
            long long int m = min(height[start],height[end]);
            // now find the area contained between this lines and the x-axis
            area = m*(end-start);
            // if area>max
            // then update max
            if(area>max_area){
                max_area = area;
            }
            // now update the pointer for which the height of the vertical line is smaller
            if(height[start]>height[end]){
                end--;
            }
            else{
                start++;
            }

        }
        // return maximum area
        return max_area;
        
    }
};
