#include"grid.h"
#include<iostream>
#include"colors.h"
Grid::Grid(){
    numRows =20;
    numCols =10;
    cellSize =30;
    Initialize();
    colors =GetCellColors();
}
void :: Grid :: Initialize(){
    for(int rows= 0; rows<numRows ;rows++){
        for(int cols =0; cols<numCols;cols++){
            grid[rows][cols]=0;
        }
    }
}
void :: Grid :: Print(){
    for(int rows= 0; rows<numRows ;rows++){
        for(int cols =0; cols<numCols;cols++){
          std:: cout<<grid[rows][cols]<<" ";
        }
        std:: cout<< std:: endl;
    }
}

void Grid:: Draw(){
     for(int rows= 0; rows<numRows ;rows++){
        for(int cols =0; cols<numCols;cols++){
           int cellValue = grid[rows][cols];
           DrawRectangle(cols* cellSize+1,rows * cellSize+1,cellSize-1,cellSize-1,colors[cellValue]);
        }
    }
} 
bool Grid:: IsCellOutside (int row, int column)
{
    if(row>= 0 && row <numRows && column >=0 && column< numCols){
        return false;
    }
    else return true;
}
bool Grid:: IsCellEmpty(int row, int column){
    if(grid[row][column]==0){
        return true;
    }
    else return false;
}

bool Grid:: IsRowFull(int row){
    for(int column =0 ; column < numCols ;column ++)
{
    if(grid[row][column]==0)
    {
        return false;
    }
}
return true;
}

void Grid:: ClearRow(int row){
       for(int column =0 ; column < numCols ;column ++)
{
    grid[row][column] = 0;
}
}

void Grid:: MoveRowDown(int row, int numRows)
{
    for (int column =0 ; column < numCols ; column++){
        grid[row +numRows][column] =grid[row][column];
        grid[row][column] =0;
    }
}

int Grid:: ClearFullRows(){
    int completed = 0;
    for(int row = numRows-1; row >=0 ;row --)
    {
        if(IsRowFull(row)){
            ClearRow(row);
            completed++;
        }
        else if(completed>0)
        {
            MoveRowDown(row ,completed);
        }
    }
    return completed;   
}