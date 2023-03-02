   int compress(vector<char>& chars) {
    int n = chars.size();
    if (n == 1) { // if there's only one character in the array, return 1
        return 1;
    }
    
    int index = 0; // index to keep track of the current position in the modified array
    int count = 1; // count to keep track of the number of consecutive characters
    
    for (int i = 1; i < n; i++) {
        if (chars[i] == chars[i-1]) { // if the current character is the same as the previous character
            count++; // increment the count
        } else { // if the current character is different from the previous character
            chars[index++] = chars[i-1]; // add the previous character to the modified array
            
            if (count == 1) { // if there was only one consecutive character, don't add the count
                // do nothing
            } else if (count < 10) { // if the count is less than 10, add the count as a single digit
                chars[index++] = count + '0'; // add the count as a character to the modified array
            } else { // if the count is 10 or more, add the count as multiple digits
                string s = to_string(count); // convert the count to a string
                for (char c : s) { // loop through each character in the string and add it to the modified array
                    chars[index++] = c;
                }
            }
            
            count = 1; // reset the count to 1 for the new group of consecutive characters
        }
    }
    
    // add the last group of consecutive characters to the modified array
    chars[index++] = chars[n-1];
    if (count == 1) {
        // do nothing
    } else if (count < 10) {
        chars[index++] = count + '0';
    } else {
        string s = to_string(count);
        for (char c : s) {
            chars[index++] = c;
        }
    }
    
    return index; // return the new length of the modified array
}
