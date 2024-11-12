#pragma once
#include"grid.h"
#include "blocks.cpp"


class Game{
public:
    Game();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    Grid grid;
    void Draw();
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    void RotateBlock();
    void Restart();
    bool gameOver;
 
private:
    bool IsBlockOutside();
    void LockBlock();
    bool BlockFits();
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};