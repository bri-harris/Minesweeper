#include "Worker.h"
#include "Window.h"
#include <iostream>

namespace Worker {
    Board CreateBoardFromFile(string cfgFile) {
        ifstream configFile(cfgFile);
        unsigned int columns, rows, mines;
        configFile >> columns;
        configFile >> rows;
        configFile >> mines;
        return Board(columns, rows, mines);
    }
    Window CreateWindowFromBoard(Board &board) {
        return Window(board);
    }
    unsigned int GetMineNumFromConfig(string cfgFile) {
        ifstream configFile(cfgFile);
        unsigned int mines;
        configFile >> mines;
        configFile >> mines;
        configFile >> mines;
        return mines;
    }
    void SetNieghtbors(vector<vector<Tile> > &tileBoard) {
        int rows = tileBoard.size();
        int columns = tileBoard[0].size();
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < columns; y++) {
                if (x == 0) {
                    if (y == 0) {
                        tileBoard[x][y].SetAdjacent(&tileBoard[x + 1][y]);
                        tileBoard[x][y].SetAdjacent(&tileBoard[x + 1][y + 1]);
                        tileBoard[x][y].SetAdjacent(&tileBoard[x][y + 1]);
                    } else if (y == columns - 1) {
                        tileBoard[x][y].SetAdjacent(&tileBoard[x][y - 1]);
                        tileBoard[x][y].SetAdjacent(&tileBoard[x + 1][y - 1]);
                        tileBoard[x][y].SetAdjacent(&tileBoard[x + 1][y]);
                    } else {
                        tileBoard[x][y].SetAdjacent(&tileBoard[x][y - 1]);
                        tileBoard[x][y].SetAdjacent(&tileBoard[x][y + 1]);
                        tileBoard[x][y].SetAdjacent(&tileBoard[x + 1][y]);
                        tileBoard[x][y].SetAdjacent(&tileBoard[x + 1][y - 1]);
                        tileBoard[x][y].SetAdjacent(&tileBoard[x + 1][y + 1]);
                    }
                } else if (x == rows - 1) {
                    if (y == 0) {
                        tileBoard[x][y].SetAdjacent(&tileBoard[x - 1][y]);
                        tileBoard[x][y].SetAdjacent(&tileBoard[x - 1][y + 1]);
                        tileBoard[x][y].SetAdjacent(&tileBoard[x][y + 1]);
                    } else if (y == columns - 1) {
                        tileBoard[x][y].SetAdjacent(&tileBoard[x - 1][y]);
                        tileBoard[x][y].SetAdjacent(&tileBoard[x - 1][y - 1]);
                        tileBoard[x][y].SetAdjacent(&tileBoard[x][y - 1]);
                    } else {
                        tileBoard[x][y].SetAdjacent(&tileBoard[x][y - 1]);
                        tileBoard[x][y].SetAdjacent(&tileBoard[x][y + 1]);
                        tileBoard[x][y].SetAdjacent(&tileBoard[x - 1][y]);
                        tileBoard[x][y].SetAdjacent(&tileBoard[x - 1][y - 1]);
                        tileBoard[x][y].SetAdjacent(&tileBoard[x - 1][y + 1]);
                    }
                } else if (y == 0) {
                    tileBoard[x][y].SetAdjacent(&tileBoard[x - 1][y]);
                    tileBoard[x][y].SetAdjacent(&tileBoard[x - 1][y + 1]);
                    tileBoard[x][y].SetAdjacent(&tileBoard[x + 1][y]);
                    tileBoard[x][y].SetAdjacent(&tileBoard[x + 1][y + 1]);
                    tileBoard[x][y].SetAdjacent(&tileBoard[x][y + 1]);
                } else if (y == columns - 1) {
                    tileBoard[x][y].SetAdjacent(&tileBoard[x - 1][y]);
                    tileBoard[x][y].SetAdjacent(&tileBoard[x - 1][y - 1]);
                    tileBoard[x][y].SetAdjacent(&tileBoard[x][y - 1]);
                    tileBoard[x][y].SetAdjacent(&tileBoard[x + 1][y - 1]);
                    tileBoard[x][y].SetAdjacent(&tileBoard[x + 1][y]);
                } else {
                    tileBoard[x][y].SetAdjacent(&tileBoard[x][y - 1]);
                    tileBoard[x][y].SetAdjacent(&tileBoard[x][y + 1]);
                    tileBoard[x][y].SetAdjacent(&tileBoard[x - 1][y]);
                    tileBoard[x][y].SetAdjacent(&tileBoard[x - 1][y - 1]);
                    tileBoard[x][y].SetAdjacent(&tileBoard[x - 1][y + 1]);
                    tileBoard[x][y].SetAdjacent(&tileBoard[x + 1][y]);
                    tileBoard[x][y].SetAdjacent(&tileBoard[x + 1][y - 1]);
                    tileBoard[x][y].SetAdjacent(&tileBoard[x + 1][y + 1]);
                }
            }
        }
    }

    vector<vector<char> > ReadInTestLayout(string testPath) {
        ifstream testFile(testPath);
        vector<vector<char> > cfgLayout(0);

        string line;

        while (getline(testFile, line)) {
            vector<char> rows(0);

            while (line.size() > 0) {
                char c;
                int temp = stoi(line.substr(0, 1));
                if (temp == 0) c = ' ';
                else if (temp == 1) c = 'x';
                line = line.substr(1, line.size() - 1);
                rows.push_back(c);
            }

            cfgLayout.push_back(rows);
        }
        return cfgLayout;
    }
    void SetupTestBoard(Board &board, string testPath) {
        board.ResetBoard();

        vector<vector<char> > newLayout = ReadInTestLayout(testPath);
        board.SetTileLayout(newLayout);

        board.PlantMines();
    }
    void BuildBoard(Board &board, sf::RenderWindow &rWindow) {
        vector<vector<Tile> > &tileLayout = board.GetTileLayout();
        for (int i = 0; i < tileLayout.size(); i++) {
            for (int j = 0; j < tileLayout[i].size(); j++) {
                tileLayout[i][j].SetPosition((j * 32), (i * 32));
                rWindow.draw(tileLayout[i][j].GetTileSprite());

                if (tileLayout[i][j].HasMine()) rWindow.draw(tileLayout[i][j].GetMineSprite());
                if (tileLayout[i][j].HasNumber()) rWindow.draw(tileLayout[i][j].GetNumberSprite());

                if (tileLayout[i][j].isFlagged() && !tileLayout[i][j].isRevealed()) {
                    rWindow.draw(tileLayout[i][j].GetFlagSprite());
                } else if (tileLayout[i][j].isFlagged() && tileLayout[i][j].isRevealed()) {
                    rWindow.draw(tileLayout[i][j].GetTileSprite());
                    rWindow.draw(tileLayout[i][j].GetFlagSprite());
                    rWindow.draw(tileLayout[i][j].GetMineSprite());
                }
            }
        }
    }

    void DrawMenu(Window &window, sf::RenderWindow &rWindow) {
        window.SetPosition(window._smileX, window._smileY);
        rWindow.draw(window._happy);
        rWindow.draw(window._debug);
        rWindow.draw(window._test1);
        rWindow.draw(window._test2);
        rWindow.draw(window._test3);
    }
    void DrawWon(Window &window, sf::RenderWindow &rWindow) {
        rWindow.draw(window._win);
    }
    void DrawLost(Window &window, sf::RenderWindow &rWindow) {
        rWindow.draw(window._lose);
    }
    void DrawSmile(Window &window, sf::RenderWindow &rWindow) {
        rWindow.draw(window._happy);
    }
    void DrawDigits(Board &board, sf::RenderWindow &rWindow) {
        board.SetDigits(board._digitsX, board._digitsY);
        rWindow.draw(board._hundredsDigit);
        rWindow.draw(board._tensDigit);
        rWindow.draw(board._onesDigit);
    }

    void DebugToggle(vector<vector<Tile> > &tileLayout, sf::RenderWindow &rWindow) {
        sf::Sprite mine(TextureManager::GetTexture("mine"));

        for (int i = 0; i < tileLayout.size(); i++) {
            for (int j = 0; j < tileLayout[i].size(); j++) {
                if (tileLayout[i][j].HasMine()) {
                    mine.setPosition((j * 32), (i * 32));
                    rWindow.draw(mine);
                }
            }
        }
    }
    bool CheckWin(Board &board) {
        int tR = board.TilesRevealed();
        int fMc = board.FlagMineCount();
        if (fMc == board.GetMines() && tR == board.TilesEligible()) {
            board.SetWin();
            return true;
        }
        return false;
    }
}
