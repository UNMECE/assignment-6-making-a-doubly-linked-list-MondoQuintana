#include "coordinate.h"
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;

int main(int argc, char*argv[])
{
    srand(time(0));
    int max_coord;
    max_coord = atoi(argv[1]);

    for (int i = 0; i < max_coord; i++)
    {
        int coord_id = i+1;
        float x = rand()%100;
        float y = rand()%100;
        add_coordinate(coordinateList, x, y, coord_id);
    }

    forward_display(coordinateList, max_coord);
    backward_display(coordinateList, max_coord);

    int coord_id_to_delete = 1 + rand() % max_coord;
    cout<<"Coordinate with coordinate id of "<<coord_id_to_delete<<" will be deleted."<<endl;
    delete_coordinate(coordinateList, coord_id_to_delete);
    max_coord = max_coord - 1;

    forward_display(coordinateList, max_coord);

    
    return 0;
}

void add_coordinate(std::vector <Coordinate> &coordinateList, float x, float y, int coord_id)
{
    coordinateList.push_back(Coordinate());
    coordinateList[coord_id-1].coord_id = coord_id;
    coordinateList[coord_id-1].x = x;
    coordinateList[coord_id-1].y = y;
    cout <<"Coordinate added at index "<<coord_id-1<<" with coordinate id of "<<coord_id<<". X = "<<x<<", Y = "<<y<<"."<<endl;
}

void forward_display(std::vector <Coordinate> &coordinateList, int max_coord)
{
    for (int i = 0; i < max_coord; i++)
    {
        cout<<"Coordinate at index "<<i<<" with coordinate id of "<<coordinateList[i].coord_id<<". X = "<<coordinateList[i].x<<", Y = "<<coordinateList[i].y<<"."<<endl;
    }
    
}

void backward_display(std::vector <Coordinate> &coordinateList, int max_coord)
{
    for (int i = max_coord-1; i >= 0; i--)
    {
        cout<<"Coordinate at index "<<i<<" with coordinate id of "<<coordinateList[i].coord_id<<". X = "<<coordinateList[i].x<<", Y = "<<coordinateList[i].y<<"."<<endl;
    }
    
}

void delete_coordinate(std::vector <Coordinate> &coordinateList, int coord_id_to_delete)
{
    coordinateList.erase(coordinateList.begin()+coord_id_to_delete-1);
}