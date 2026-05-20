class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {

        Set<Integer> a1 = new HashSet<>();
        Set<Integer> b1 = new HashSet<>();
        int common =0;
          int n = A.length;
        int[] ans = new int[n];

      

        for(int i=0;i<n;i++){

            a1.add(A[i]);
            b1.add(B[i]);

           
            if(a1.contains(B[i])) common++;
            if(b1.contains(A[i]) && A[i]!=B[i]) common++;

            ans[i] = common;


        }

        return ans;


        
    }
}