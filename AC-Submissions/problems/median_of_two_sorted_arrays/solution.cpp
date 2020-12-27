class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int cntr = 0;
        int m = nums1.size();
        int n = nums2.size();
        int a = (n+m)/2  , b = (n+m)/2 -1; 
        double A,B;
        for(int i = 0 , j = 0; cntr < n + m; cntr++){
            if(cntr>a)break;
            if(j==n){
                if(cntr==b)B = nums1[i];
                if(cntr==a)A = nums1[i];
                i++;continue;
            }
            if(i==m){
               if(cntr==b)B = nums2[j];
                if(cntr==a)A = nums2[j];j++;continue;
            }
            if(nums1[i]>nums2[j]){
                if(cntr==b)B = nums2[j];
                if(cntr==a)A = nums2[j];
                j++;
            }
            else {
               if(cntr==b)B = nums1[i];
                if(cntr==a)A = nums1[i];i++;
            }
        }
        double C=0.0;
        if((n+m) % 2){
            
            return {A};
        }
        else {
            C = (A+B)/2.0;
            return {C};
        }
    }
    
};