#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class RatInAMaze
{

public:
    vector<string> ratInMaze(vector<vector<int>> maze);

private:
    void possiblePath(vector<vector<int>> maze, int finalRow, int finalCol, vector<vector<int>> travelledPath, int curRow, int curCol, string output, vector<string> &response);
    bool validMove(vector<vector<int>> maze, int finalRow, int finalCol, vector<vector<int>> &travelledPath, int curRow, int curCol);
};
bool RatInAMaze::validMove(vector<vector<int>> maze, int finalRow, int finalCol, vector<vector<int>> &travelledPath, int curRow, int curCol)
{

    if ((curRow >= 0 && curCol >= 0) && (curRow < finalRow && curCol < finalCol) && (maze[curRow][curCol] == 1) && (travelledPath[curRow][curCol] == 0))
    {
        return true;
    }
    return false;
}
void RatInAMaze::possiblePath(vector<vector<int>> maze, int finalRow, int finalCol, vector<vector<int>> travelledPath, int curRow, int curCol, string output, vector<string> &response)
{
    // handle base case
    if (curRow == finalRow-1 && curCol == finalCol-1)
    {
        response.push_back(output);
        return;
    }
    travelledPath[curRow][curCol] = 1; // path travelled

    // Move Right
    int newRow = curRow;
    int newCol = curCol + 1;
    // before moving check valid move
    if (validMove(maze, finalRow, finalCol, travelledPath, newRow, newCol))
    {
       // cout << "R";
        output += "R";
        possiblePath(maze, finalRow, finalCol, travelledPath, newRow, newCol, output, response);
        output.pop_back();
    }

    // Move Left
    newRow = curRow;
    newCol = curCol - 1;
    if (validMove(maze, finalRow, finalCol, travelledPath, newRow, newCol))
    {
       // cout << "L";
        output += "L";
        possiblePath(maze, finalRow, finalCol, travelledPath, newRow, newCol, output, response);
        output.pop_back();
    }

    // move UP
    newRow = curRow - 1;
    newCol = curCol;
    if (validMove(maze, finalRow, finalCol, travelledPath, newRow, newCol))
    {
       // cout << "U";
        output += "U";
        possiblePath(maze, finalRow, finalCol, travelledPath, newRow, newCol, output, response);
        output.pop_back();
    }

    // Move Down
    newRow = curRow + 1;
    newCol = curCol;
    if (validMove(maze, finalRow, finalCol, travelledPath, newRow, newCol))
    {
       // cout << "D";
        output += "D";
        possiblePath(maze, finalRow, finalCol, travelledPath, newRow, newCol, output, response);
        output.pop_back();
    }
    travelledPath[curRow][curCol] = 0; // reset Traveled path for next path;
}
vector<string> RatInAMaze::ratInMaze(vector<vector<int>> maze)
{

    vector<string> response;
    if (maze.size() == 0)
    {
        return response;
    }

    int curRow{0};
    int curCol{0};

    int finalRow = maze.size();
    int finalCol = (maze.empty()) ? 0 : maze[0].size();

    vector<vector<int>> travelledPath = maze;
    string output = "";
    for (int i = 0; i < finalRow; i++)
    {
        for (int j = 0; j < finalCol; j++)
        {
            travelledPath[i][j] = 0;
        }
    }
    possiblePath(maze, finalRow, finalCol, travelledPath, curRow, curCol, output, response);
    sort(response.begin(), response.end());
    return response;
}

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    RatInAMaze rz;
    // Call ratInMaze and get the result
    vector<string> result = rz.ratInMaze(maze);

    // Print result in the main function
    if (result.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        for (const auto &p : result)
        {
            cout << p << " ";
        }
        cout << endl;
    }

    return 0;
}