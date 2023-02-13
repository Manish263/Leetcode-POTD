Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

 int countOdds(int l, int h) {
        return (h+1)/2 -(l/2);
    }
