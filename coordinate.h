#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>
#include <cmath>
#include <cstdlib>

struct _coordinate
{
  float x;
  float y;
  int coord_id;
  struct _coordinate *next;
  struct _coordinate *previous;
};

typedef struct _coordinate Coordinate;


void add_coordinate(Coordinate *&tail, float x, float y);
void forward_display(Coordinate *head);
void backward_display(Coordinate *tail);
void delete_coordinate(Coordinate *&head, int coord_id_to_delete);
int list_length(Coordinate *head);
void closest_to(Coordinate *head, float x, float y);

#endif
