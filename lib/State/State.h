#ifndef _STATE_H
#define _STATE_H

typedef enum COLOR{
    NO_COLOR,
    RED,
    YELLOW, // R+G
    GREEN,
    MAGENTA, // G+B
    BLUE,
    CYAN, // B+R
    BLACK, // no light
    WHITE // R+G+B
} Color;

#endif