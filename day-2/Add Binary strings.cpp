string addBinary(string a, string b) {
    int carry = 0;
    int i = a.length() - 1,j = b.length() - 1; //initialize pointer i,j to the last index of string a,b.
    string result = "";
    while (i >= 0 || j >= 0 || carry != 0) { //continue loop until all digits of both strings and carry have been processed
        int sum = carry;
        if (i >= 0) {
            sum += (a[i] - '0');  //ifadd the ith digit of a to sum and decrement i
            i--;
        }
        if (j >= 0) {
            sum += (b[j] - '0');//add the jth digit of b to sum and decrement j
            j--;
        }
        result = to_string(sum % 2) + result; //append the remainder of sum divided by 2 to the front of result
        carry = sum / 2; //set carry to the quotient of sum divided by 2
    }
    
    return result; //return the final binary sum as a string
}
