class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
     if (s1.length() > s2.length()) return false;

        vector<int> s1Count(26, 0);
        vector<int> windowCount(26, 0);

        // 1. Populate the frequency maps for s1 and the first window of s2
        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1[i] - 'a']++;
            windowCount[s2[i] - 'a']++;
        }

        // 2. Slide the window over the rest of s2
        for (int i = s1.length(); i < s2.length(); i++) {
            // Check if the previous window was a match
            if (s1Count == windowCount) return true;

            // Include the new character entering the window from the right
            windowCount[s2[i] - 'a']++;
            
            // Remove the character leaving the window from the left
            windowCount[s2[i - s1.length()] - 'a']--;
        }

        // 3. Check the final window after the loop ends
        return s1Count == windowCount;
    }
};