#include <raylib.h>

#define PROGRAY    (Color){ 54, 54, 54, 255 } 

#define DARKPROGRAY        (Color){ 38, 38, 38, 255 } 

#define LIGHTPROGRAY        (Color){ 150, 150, 150, 255 } 

bool GetCollision(int x, int y , int w, int h, int x2 , int y2 , int w2 , int h2){
    if( y+h <= y2 )
    {
        return false;
    }

    if( y >= y2+h2 )
    {
        return false;
    }

    if( x+w <= x2 )
    {
        return false;
    }

    if( x >= x2+w2 )
    {
        return false;
    }

    return true;

}

typedef struct GlobalData{
    Font GlobalFont;
}GlobalData;

static GlobalData CarbonData;

int CarbonButton(int Mode , int X , int Y , int Width , int Height  , int FontSize , const char *Text ){
    if (Mode == 1){
        DrawRectangle(X , Y , Width , Height , PROGRAY);
        DrawRectangleLines(X , Y , Width , Height , WHITE);
        DrawTextEx(CarbonData.GlobalFont , Text , (Vector2){ X + (Width / 2) - (MeasureTextEx(CarbonData.GlobalFont ,Text , FontSize , 2).x / 2) , Y + FontSize / 2 } , FontSize , 2, WHITE);
        if (GetCollision(X , Y , Width , Height , GetMouseX() , GetMouseY() , 5 , 5)){
            DrawRectangleLines(X , Y , Width , Height , RED);
        }
        if (GetCollision(X , Y , Width , Height , GetMouseX() , GetMouseY() , 5 , 5) && IsMouseButtonPressed(0)){
            return true;
        }
        else {
            return false;
        }
    }
}


void CarbonText(int X , int Y , int FontSize , const char *Text ){
    DrawTextEx(CarbonData.GlobalFont , Text , (Vector2){ X , Y } , FontSize , 2, WHITE);
}

void CarbonCenterText(int YOffset , int FontSize , const char *Text ){
    DrawTextEx(CarbonData.GlobalFont , Text , (Vector2){ GetScreenWidth() / 2 - MeasureTextEx(CarbonData.GlobalFont ,Text , FontSize , 2).x / 2 , YOffset} , FontSize , 2, WHITE);
}

void CarbonPrompt(int X , int Y , int Width , int Height ,  int FontSize , const char *TitleText , const char *PromptText){
    DrawRectangle(X , Y , Width , Height , PROGRAY);
    DrawRectangle(X , Y , Width , Height / 6 , LIGHTPROGRAY);
    DrawRectangleLines(X , Y , Width , Height / 6 , WHITE);
    DrawRectangleLines(X , Y , Width , Height , WHITE);
    DrawTextEx(CarbonData.GlobalFont , TitleText , (Vector2){ X + (Width / 2) - (MeasureTextEx(CarbonData.GlobalFont ,TitleText , FontSize , 2).x / 2) , Y + 2 } , FontSize , 2, WHITE);
    DrawRectangle(X + Width / 8 , Y + Height / 2, Width - Width / 4  , Height / 6  , LIGHTPROGRAY);
    DrawRectangleLines(X + Width / 8 , Y + Height / 2, Width - Width / 4  , Height / 6  , WHITE);

    if (GetCollision(X + Width / 8 , Y + Height / 2, Width - Width / 4  , Height / 6 , GetMouseX() , GetMouseY() , 5 , 5) && IsMouseButtonDown(0)){
        DrawRectangleLines(X + Width / 8 , Y + Height / 2, Width - Width / 4  , Height / 6  , RED);
    }

}
