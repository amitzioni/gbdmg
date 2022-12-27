// screen.c - Implementing the Gameboy screen and graphics using Xlib

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <stdbool.h>
#include <X11/Xlib.h>

#include "defs.h"
#include "memory.h"
#include "hw_regs.h"

#define GB_SCREEN_WIDTH 160
#define GB_SCREEN_HEIGHT 144
#define EMU_SCREEN_SCALE 5
#define EMU_SCREEN_WIDTH ((GB_SCREEN_WIDTH) * (EMU_SCREEN_SCALE))
#define EMU_SCREEN_HEIGHT ((GB_SCREEN_HEIGHT) * (EMU_SCREEN_SCALE))
#define EMU_SCREEN_BORDER 1

typedef enum{
    COLOR_0 = 0,
    COLOR_1,
    COLOR_2,
    COLOR_3,
}color;

unsigned long color_values[4] = {
    [COLOR_0] = 0x0F380F,
    [COLOR_1] = 0x306230,
    [COLOR_2] = 0x8BAC0F,
    [COLOR_3] = 0x9BBC0F,
};

Display *dis;
Window win;
XEvent xev;
GC gc;
int screen;

static Byte *tile_array1_obj[256];
static Byte *tile_array0[256];

static Byte *tile_map0[32][32];
static Byte *tile_map1[32][32];

static Byte *oam_table[40];

void initGraphics(char *rom_title){


    // Initialize Xlib Graphics and Input
    if((dis = XOpenDisplay(NULL)) == NULL)
    {
        fprintf(stderr, "Error in %s: Cannot open display\n", __func__);
        exit(EXIT_FAILURE);
    }
    screen = DefaultScreen(dis);
    win = XCreateSimpleWindow(dis, RootWindow(dis, screen), 80, 80, EMU_SCREEN_WIDTH, EMU_SCREEN_HEIGHT,
            EMU_SCREEN_BORDER, BlackPixel(dis, screen), WhitePixel(dis, screen));
    XStoreName(dis, win, rom_title);
    gc = DefaultGC(dis, screen);

    XSelectInput(dis, win, ExposureMask | KeyPressMask | KeyReleaseMask);
    XMapWindow(dis, win);
    XFlush(dis);
    XNextEvent(dis, &xev);


    // Initialize tile / obj arrays 
    for(int i = 0; i < 256; i++)
    {
        tile_array1_obj[i] = getMemoryPointer(0x8000 + (i * 16));
        if(i <= 127)
            tile_array0[i] = getMemoryPointer(0x9000 + (i * 16));
        else
            tile_array0[i] = getMemoryPointer(0x8000 + (i * 16));
        
    }

    // Initialize tile maps
    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < 32; j++)
        {
            tile_map0[i][j] = getMemoryPointer(0x9800 + (i * 32) + j);
            tile_map1[i][j] = getMemoryPointer(0x9C00 + (i * 32) + j);
        }
    }

    // Initialize OAM map
    for(int i = 0; i < 40; i++)
        oam_table[i] = getMemoryPointer(0xFE00 + (i * 4));
}

void setPixel(int x, int y, color cl){
    assert(x >= 0 && x <= GB_SCREEN_WIDTH);
    assert(y >= 0 && y <= GB_SCREEN_HEIGHT);
    assert(cl >= COLOR_0 && cl <= COLOR_3);

    XSetForeground(dis, gc, color_values[cl]);
    XFillRectangle(dis, win, gc, x * EMU_SCREEN_SCALE, y * EMU_SCREEN_SCALE, 
            EMU_SCREEN_SCALE, EMU_SCREEN_SCALE);
    XFlush(dis);
}


void drawTileLine(int x, int y, Byte msb, Byte lsb){
    for(int i = 0; i < 8; i++)
    {
        Byte mask = (1 << (7 - i));
        color cl = ((msb & mask) ? 2 : 0);
        cl += ((lsb & mask) ? 1 : 0);
        setPixel(x + i, y, cl);
    }
}

void drawObjLine(int x, int y, Byte msb, Byte lsb){
    for(int i = 0; i < 8; i++)
    {
        Byte mask = (1 << (7 - i));
        color cl = ((msb & mask) ? 2 : 0);
        cl += ((lsb & mask) ? 1 : 0);
        if(cl != COLOR_0)
            setPixel(x + i, y, cl);
    }
}

void drawTile(int x, int y, int tile_id){
    bool lcdc_4_status = (getMemory(HWR_LCDC) & (1 << 4));

    if(lcdc_4_status)
    {
        for(int i = 0; i < 8; i++)
        {
            Byte lsb = *(tile_array1_obj[tile_id + (i * 2)]);
            Byte msb = *(tile_array1_obj[tile_id + (i * 2) + 1]);
            drawTileLine(x, y + i, msb, lsb);
        }
    }
    else
    {
        for(int i = 0; i < 8; i++)
        {
            Byte lsb = *(tile_array0[tile_id + (i * 2)]);
            Byte msb = *(tile_array0[tile_id + (i * 2) + 1]);
            drawTileLine(x, y + i, msb, lsb);
        }
    }
}

void drawScreen(void){

    
}
