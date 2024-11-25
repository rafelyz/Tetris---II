#include "grid.h"
#include<iostream>
#include "color.h"

Grid:: Grid()

{
    noofrow = 20;
    noofcol = 10;
    cellsize=30;
    Initialize();
    colors = GetCellcolors();

}


void Grid::Initialize()
{
    for(int row=0;row<noofrow;row++)
    {
        for(int col=0;col<noofcol ; col++)
        {
            grid[row][col] =0;
        }
    }
}

void Grid::Print()
{
    for(int row=0;row<noofrow;row++)
    {
        for(int col=0;col<noofcol ; col++)
        {
            std::cout<<grid[row][col] << " ";
        }
        std::cout<< std::endl;
    }
}




void Grid:: Draw()
{
    for(int row=0;row<noofrow;row++)
    {
        for(int col=0;col<noofcol ; col++)
        {
            int cellValue = grid[row][col];
            DrawRectangle(col*cellsize +11 ,row * cellsize+11,cellsize-1,cellsize-1, colors[cellValue]);
        }
        std::cout<< std::endl;
    }
}

bool Grid::IsCellOutside(int row, int column)
{
    if (row>=0 && row<noofrow && column >= 0 && column <noofcol)
    {
        return false;

    }
    return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
    if (grid[row][column]==0)
    {
        return true;
    }
    return false ;
}

int Grid::ClearFullRows()
{
    int completed =0;
    for(int row=noofrow-1; row>=0;row--)
    {
        if(IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed>0)
        {
            MoveRowDown(row,completed);
        }
    }
    return completed;
}

bool Grid::IsRowFull(int row)
{
    for(int column =0;column <noofcol; column++ )
    {
        if(grid[row][column]==0)
        {
            return false ;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for(int column =0; column< noofcol;column++)
    {
        grid[row][column]=0;
    } 
}

void Grid::MoveRowDown(int row, int numRows)
{
    for(int column =0; column <noofcol;column++)
    {
        grid[row + numRows ][column]= grid[row][column];
        grid[row][column]=0;
    }

}
