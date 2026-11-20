#ifndef LANE_H
#define LANE_H

#include "raylib.h"

#define LANE_COUNT 4

typedef struct {
Rectangle bounds;
} lane;

void InitLane(lane lanes[]);
void DrawLane(lane lanes[]);

#endif

