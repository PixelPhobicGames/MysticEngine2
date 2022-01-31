// @ PixelPhobicGames 2022

#include "Core.hpp"

int main(void){

    MysticEngineInit();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        
        ClearBackground(BLACK);

        UpdateMusicStream(WorldData.Theme);

        RenderLevel();
        CoreUpdate();

        CustomLevelBehavior();


        if (IsKeyPressed(KEY_F11)){
            ToggleFullscreen();
        }


        EndDrawing();
    }
    CloseWindow();
    
}