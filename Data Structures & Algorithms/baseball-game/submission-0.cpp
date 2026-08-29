class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scoreStack;
      
        // Process each operation in the operations array
        for (const auto& operation : operations) {
            int stackSize = scoreStack.size();
          
            if (operation == "+") {
                // Add the sum of the last two scores to the stack
                int sumOfLastTwo = scoreStack[stackSize - 1] + scoreStack[stackSize - 2];
                scoreStack.push_back(sumOfLastTwo);
            } 
            else if (operation == "D") {
                // Double the last score and add it to the stack
                int doubledScore = scoreStack[stackSize - 1] * 2;  // Using * 2 instead of << 1 for clarity
                scoreStack.push_back(doubledScore);
            } 
            else if (operation == "C") {
                // Cancel/remove the last score from the stack
                scoreStack.pop_back();
            } 
            else {
                // The operation is a number, convert it to integer and add to stack
                int score = stoi(operation);
                scoreStack.push_back(score);
            }
        }
      
        // Calculate and return the sum of all valid scores
        return accumulate(scoreStack.begin(), scoreStack.end(), 0);
    }
};