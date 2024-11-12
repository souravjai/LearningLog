package TopInterview150;

/*
* TC: O(N+M)
* SC: O(1)

To sort in ascending order just start from back of all array and sort in descding order
*/
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        
        int i1 = m-1, i2 = n-1;
        int i = m+n-1;
        
        while(i1>=0 && i2>=0){
            if(nums1[i1]<nums2[i2]){
                nums1[i--] = nums2[i2--];
            }else{
                nums1[i--] = nums1[i1--];
            }
        }
        while(i1>=0){
            nums1[i--] = nums1[i1--];
        }
        while(i2>=0){
            nums1[i--] = nums2[i2--];
        }

    }
}


/*
* TC: O(N+M)
* SC: O(1)

This solution does extra work to push all element back
*/
class SolutionOld {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
    
        for(int i = 1 ; i <= m ; i++){
            nums1[m+n-i] = nums1[m-i];
        }
        
        int i1 = n, i2 = 0;
        int i = 0;
        while(i1<m+n && i2<n){
            if(nums1[i1]<nums2[i2]){
                nums1[i++] = nums1[i1++];
            }else{
                nums1[i++] = nums2[i2++];
            }
        }
        while(i1<m+n){
            nums1[i++] = nums1[i1++];
        }
        while(i2<n){
            nums1[i++] = nums2[i2++];
        }

    }
}