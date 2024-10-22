#include "coordinate.h"
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

int main(int argc, char*argv[])
{
    //generate random seed
    srand(time(0));
    //take argument from line for max size of vector
    int max_coord;
    max_coord = atoi(argv[1]);

    //generate coordinate vector
    for (int i = 0; i < max_coord; i++)
    {
        int coord_id = i+1;
        float x = rand()%100;
        float y = rand()%100;
        add_coordinate(coordinateList, x, y, coord_id);
    }

    //display vector forward and back
    forward_display(coordinateList, max_coord);
    backward_display(coordinateList, max_coord);

    //generate coord id to delete between 1 and max_coord
    int coord_id_to_delete = 1 + rand() % max_coord;
    cout<<"Coordinate with coordinate id of "<<coord_id_to_delete<<" will be deleted."<<endl;
    //delete coord at ID
    delete_coordinate(coordinateList, coord_id_to_delete);
    //lower max coord and print new vector
    max_coord = max_coord - 1;
    forward_display(coordinateList, max_coord);

    //get size of current vect
    int size = list_length(coordinateList);
    cout<<"Size of current list: "<<size<<endl;

    //calculate the closest coordinate to a randomly generated coordinate
    closest_coord(coordinateList, size);


    
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

int list_length(std::vector <Coordinate> &coordinateList)
{
    return coordinateList.size();
}

void closest_coord(std::vector <Coordinate> &coordinateList, int current_size_of_vector)
{
    double distance;
    double min_distance;
    int closest_coord_id;
    float new_x = rand()%100;
    float new_y = rand()%100;
    for (int i = 0; i < current_size_of_vector; i++)
    {
        distance = sqrt(pow(coordinateList[i].x-new_x,2)+pow(coordinateList[i].y-new_y,2));
        if (i==0)
        {
            min_distance = distance;
            closest_coord_id = coordinateList[i].coord_id;
        }
        else if (i>0)
        {
            if (distance<min_distance)
            {
                min_distance=distance;
                closest_coord_id = coordinateList[i].coord_id;
            }
            
        }
        
    }
    
    cout<<"New Coord is X="<<new_x<<" and Y="<<new_y<<"."<<endl; cout<<"Closest coordinate is Coord ID: "<<closest_coord_id<<". With a distance of "<<min_distance<<"."<<endl;

}