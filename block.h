#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "color.h"
 class Block
 {
    public:
    Block();
    void Draw(int offsetX,int offsetY);
    void Move(int rows, int columns);
    std::vector<Position> GetCellPositions();
    void Rotate();
    void UndoRotation();

    int id;

    std:: map<int , std::vector <Position >>cells;
    private:
    int cellsize;
    int rotationstate;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;


 };