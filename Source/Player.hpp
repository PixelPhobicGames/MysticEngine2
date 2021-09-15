#include <string>
#include <iostream>
#include <fstream>
#include <raylib.h>
#include <stdlib.h>
#include <cstring>

typedef struct Player{
    int X;
    int Y;
    int Direction;
    int JumpCounter;
    int JumpTrigger;
    int Width;
    int Height;
    int AnimationSpeed;
    int AnimationTicker;
    
    Texture2D AnimationFrame1;
    Texture2D AnimationFrame2;
    Texture2D AnimationFrame3;
    Texture2D AnimationFrame4;
    Texture2D AnimationFrame5;
    Texture2D AnimationFrame6;
    Texture2D AnimationFrame7;
    Texture2D AnimationFrame8;
    Texture2D AnimationFrame9;
    Texture2D AnimationFrame10;
    Texture2D AnimationFrame11;
    Texture2D AnimationFrame12;
    Texture2D AnimationFrame13;
    Texture2D AnimationFrame14;
    Texture2D AnimationFrame15;
    Texture2D AnimationFrame16;
    Texture2D AnimationFrame17;
    Texture2D AnimationFrame18;
    Texture2D AnimationFrame19;
    Texture2D AnimationFrame20;

    int YOffset;
}Player;

static Player MysticPlayer;
