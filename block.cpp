#include "block.h"
Block::Block()
{
    cellsize = 30;
    rotationstate = 0;
    colors = GetCellcolors();
    rowOffset= 0;
    columnOffset =0;
}

void Block :: Draw(int offsetX,int offsetY)
{
    std::vector<Position>tiles = GetCellPositions();
    for (Position item: tiles )
    {
        DrawRectangle(item.column * cellsize +offsetX, item.row* cellsize+offsetY,cellsize -1, cellsize-1 , colors[id] );
    }
}

void Block ::Move(int rows,int columns)
{
    rowOffset += rows;
    columnOffset += columns;

}
std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationstate ];
    std::vector<Position >movedTiles;
    for(Position item: tiles )
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos); 
    }
    return movedTiles;

}

void Block::Rotate()
{
    rotationstate ++;
    if (rotationstate ==(int) cells.size())
    {
        rotationstate =0;
    }
}

void Block::UndoRotation()
{
    rotationstate --;
    if(rotationstate == -1)
    {
        rotationstate = cells.size()-1;
    }
}
