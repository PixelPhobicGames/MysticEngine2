
#include "Player.hpp"

using namespace std;

typedef struct CoreData
{
    float WindowScale;
    int IntScale;
    int LevelId;
    wstring MapDataConfig;
    bool GameEnd;
    bool EditMode;
    int EditCursorX;
    int EditCursorY;
    int XResolution;
    int YResolution;
    int BackgroundXScroll;
    int BackgroundXScrollSpeed;
    wchar_t EditorTile;
    bool Debug;
    bool ME1Compatable;
    int LevelType;
    bool FirstLoad;
    int FpsScaler;
    char WindowCaption;

}CoreData;

static CoreData MysticEngine;

typedef struct MysticCamera{
    int X;
    int Y;
    int XAcceleration;
    int YAcceleration;
    int Direction;
    int Speed;

}MysticCamera;

static MysticCamera MysticEngineCamera;


typedef struct MpakData
{
    int Width;
    int Height;
    wstring Map;
    int BackgroundEnabled;
    int BackgroundScrollEnabled;
    Music Theme;


    char MapName[100];
    Texture2D Background;

    Texture2D Tile0;
    Texture2D Tile1;
    Texture2D Tile2;
    Texture2D Tile3;
    Texture2D Tile4;
    Texture2D Tile5;
    Texture2D Tile6;
    Texture2D Tile7;
    Texture2D Tile8;
    Texture2D Tile9;

}MpakData;

static MpakData WorldData;

wstring LoadFile(const char *Path){
    wstring Data;
    wifstream OutFile;
    OutFile.open(Path);
    OutFile >> Data;
    return Data;
}

wstring WriteFile(const char *Path , wstring Data){
    wofstream outfile;
    outfile.open(Path);
    outfile << Data << "\n";
}


wchar_t LoadConfigurationFile(const char *Path){
    wchar_t Data;
    wifstream outfile;
    outfile.open(Path);
    outfile >> Data;
    return Data;
}
