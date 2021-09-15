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

        if (IsKeyPressed(KEY_X)){
            MysticEngine.WindowScale -= .5f;
            SetWindowSize(MysticEngine.XResolution * MysticEngine.WindowScale, MysticEngine.YResolution * MysticEngine.WindowScale);   
        }
        if (IsKeyPressed(KEY_C)){
            MysticEngine.WindowScale += .5f;
            SetWindowSize(MysticEngine.XResolution * MysticEngine.WindowScale, MysticEngine.YResolution * MysticEngine.WindowScale);   
        }
        if (IsKeyPressed(KEY_TAB)){
            if (MysticEngine.EditMode)MysticEngine.EditMode = false;
            else{
                MysticEngine.EditMode = true;
            }
        }

        EndDrawing();
    }
    CloseWindow();
    
}