The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.
Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
  
  ANS:
      vector<int> addToArrayForm(vector<int>& a, int k) {
    int n = a.size();
        vector<int> res;
        int i = n - 1;
        int carry = k;

        // Traverse the input vector a from right to left and add the carry to each digit
        while (i >= 0 || carry > 0) {
            if (i >= 0) {
                carry += a[i];
            }
            res.push_back(carry % 10);
            carry /= 10;
            i--;
        }

        // Reverse the result vector and return it
        reverse(res.begin(), res.end());
        return res;
    }
