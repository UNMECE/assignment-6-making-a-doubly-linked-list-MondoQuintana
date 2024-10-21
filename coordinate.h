#ifndef COORDINATE_H
#define COORDINATE_H
#include <vector>


struct _coordinate
{
  float x;
  float y;
  int coord_id;
  //struct _coordinate *next;
  //struct _coordinate *previous;
};
typedef struct _coordinate Coordinate;
std::vector <Coordinate> coordinateList;
void add_coordinate(std::vector <Coordinate> &coordinateList, float x, float y, int coord_id);
void forward_display(std::vector <Coordinate> &coordinateList, int max_coord);
void backward_display(std::vector <Coordinate> &coordinateList, int max_coord);
void delete_coordinate(std::vector <Coordinate> &coordinateList, int coord_id_to_delete);
int list_length(std::vector <Coordinate> &coordinateList);
void closest_coord(std::vector <Coordinate> &coordinateList, int starting_coord);


/*
void add_coordinate(Coordinate *list_end, float x, float y);
void forward_display(Coordinate *list_beginning);
void backward_display(Coordinate *list_end);
void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete);
int list_length(Coordinate *list_beginning);
void closest_to(Coordinate *list_beginning, float x, float y);
*/

#endif
