 Node* construct(vector<vector<int>>& grid) {
    // Get the size of the grid
    int n = grid.size();
    
    // If the size of the grid is 1, create a leaf node with the value of the single element
    if (n == 1) {
        bool val = grid[0][0];
        return new Node(val, true, nullptr, nullptr, nullptr, nullptr);
    }
    
    // Check if all elements in the grid are the same
    bool isLeaf = true;
    int val = grid[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != val) {
                isLeaf = false;
                break;
            }
        }
        if (!isLeaf) break;
    }
    
    // If all elements are the same, create a leaf node with that value
    if (isLeaf) {
        return new Node(val, true, nullptr, nullptr, nullptr, nullptr);
    }
    
    // Otherwise, recursively construct the Quad-Tree for the four quadrants of the grid
    int half = n / 2;
    vector<vector<int>> topLeftGrid(half, vector<int>(half));
    vector<vector<int>> topRightGrid(half, vector<int>(half));
    vector<vector<int>> bottomLeftGrid(half, vector<int>(half));
    vector<vector<int>> bottomRightGrid(half, vector<int>(half));
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            topLeftGrid[i][j] = grid[i][j];
            topRightGrid[i][j] = grid[i][j+half];
            bottomLeftGrid[i][j] = grid[i+half][j];
            bottomRightGrid[i][j] = grid[i+half][j+half];
        }
    }
    Node* topLeft = construct(topLeftGrid);
    Node* topRight = construct(topRightGrid);
    Node* bottomLeft = construct(bottomLeftGrid);
    Node* bottomRight = construct(bottomRightGrid);
    
    // Create an internal node with the four children
    return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
}
