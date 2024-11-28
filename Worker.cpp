#include "Worker.h"
#include <iostream>

namespace Worker {

    Board CreateBoardFromFile(string cfgFile){
        ifstream configFile(cfgFile);
        unsigned int columns, rows, mines;
        configFile >> columns;
        configFile >> rows;
        configFile >> mines;
        return Board(columns,rows,mines);
    }
    Window CreateWindowFromBoard(Board& board) {
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

    vector<vector<char>> ReadInTestLayout(string testPath) {
        ifstream testFile(testPath);
        vector<vector<char>> cfgLayout(0);

        string line;

        while(getline(testFile,line)){
            vector<char> rows(0);

            while(line.size()>0){
                char c;
                int temp = stoi(line.substr(0,1));
                if (temp==0) c = ' ';
                else if (temp==1) c = 'x';
                line = line.substr(1,line.size() -1);
                rows.push_back(c);
            }

            cfgLayout.push_back(rows);
        }
        return cfgLayout;

    }
    void SetupTestBoard(Board& board, string testPath) {
        board.ResetBoard();

        vector<vector<char>> newLayout = ReadInTestLayout(testPath);
        board.SetTileLayout(newLayout);

        board.PlantMines();
    }

    void BuildBoard(Board& board,sf::RenderWindow& rWindow) {
        vector<vector<Tile>>& tileLayout = board.GetTileLayout();
        for (int i = 0; i< tileLayout.size(); i++) {
            for(int j = 0; j< tileLayout[i].size(); j++) {

                tileLayout[i][j].SetPosition((j * 32),(i*32));
                rWindow.draw(tileLayout[i][j].GetTileSprite());

                if (tileLayout[i][j].HasMine()) rWindow.draw(tileLayout[i][j].GetMineSprite());

                if (tileLayout[i][j].isFlagged() && !tileLayout[i][j].isRevealed()) {
                    rWindow.draw(tileLayout[i][j].GetFlagSprite());
                }
            }
        }

    }
    void DrawMenu(Window& window, sf::RenderWindow& rWindow) {
        DrawDigits(window,rWindow);
        window.SetPosition(window._smileX,window._smileY);
        rWindow.draw(window._happy);
        rWindow.draw(window._debug);
        rWindow.draw(window._test1);
        rWindow.draw(window._test2);
        rWindow.draw(window._test3);
    }
    void DrawDigits(Window& window, sf::RenderWindow& rWindow) {
        window.SetDigits(window._board, window._digitsX,window._digitsY);
        rWindow.draw(window._tensDigit);
        rWindow.draw(window._onesDigit);
    }


    void DebugToggle(vector<vector<Tile>>& tileLayout, sf::RenderWindow& rWindow) {
        sf::Sprite mine(TextureManager::GetTexture("mine"));

        for (int i = 0; i < tileLayout.size();i++) {
            for (int j = 0; j < tileLayout[i].size(); j++) {
                if (tileLayout[i][j].HasMine()) {
                    mine.setPosition((j * 32),(i*32));
                    rWindow.draw(mine);
                }
            }
        }
    }
}
