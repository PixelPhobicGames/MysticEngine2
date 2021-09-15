#include "Core.hpp"
using namespace std;

int main(void){
    EditorInit();    
    CarbonData.GlobalFont = LoadFont("EditorData/Font/Font.ttf");

    Camera3D Camera =  { { 0.1f, 0.8f, 0.2f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };

    int CameraDir = 1;

    SetCameraMode(Camera, CAMERA_FIRST_PERSON);

    int EditorMode = 0;

    int BootAnimation = 0;

    Texture2D BootLogo = LoadTexture("EditorData/Assets/Logo.png");

    while (BootAnimation != 120){
        BeginDrawing();
        ClearBackground(BLACK);
        BootAnimation ++;
        DrawTexture(BootLogo , 250 , 125 , WHITE);
        EndDrawing();

    }

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
		BeginDrawing();
		
        ClearBackground(DARKPROGRAY);

        switch (EditorMode){
            case 0:
                ClearBackground(BLACK);
            
                BeginMode3D(Camera);
                    DrawGrid(100, 1.0f);
                    if (Camera.position.z >= -45.0f){
                        Camera.position.z -= .5f;
                    }
                    else {

                        if (CameraDir == 1)Camera.target.x --;
                        if (CameraDir == 2)Camera.target.x ++;

                        if (Camera.target.x == -60){
                            CameraDir = 2;
                        }
                        if (Camera.target.x == 60){
                            CameraDir = 1;
                        }
                    }
                    ShowCursor(); 
                EndMode3D();

                if (CarbonButton(1 , 30* EditorWindow.Scale , 20* EditorWindow.Scale , 70* EditorWindow.Scale , 20* EditorWindow.Scale , 10* EditorWindow.Scale ,"Close" )){
                    exit(0);
                }

                CarbonCenterText(100 * EditorWindow.Scale, 40 * EditorWindow.Scale , "MysticEngine 2 Editor");

                CarbonCenterText(150 * EditorWindow.Scale, 20 * EditorWindow.Scale , "Developed By: PixelPhobicGames");

                CarbonCenterText(170 * EditorWindow.Scale, 10 * EditorWindow.Scale , "Powered By CarbonGui");

                if (CarbonButton(1 , GetScreenWidth() / 2 - (400 * EditorWindow.Scale) , 500 * EditorWindow.Scale , 200 * EditorWindow.Scale , 50 * EditorWindow.Scale, 20 * EditorWindow.Scale,"Start New Project")){EditorMode = 1;}

                if (CarbonButton(1 , GetScreenWidth() / 2 - (-200 * EditorWindow.Scale) , 500 * EditorWindow.Scale , 200 * EditorWindow.Scale , 50 * EditorWindow.Scale, 20 * EditorWindow.Scale,"Load Project")){}

                break;

            case 1:
                CarbonCenterText(20* EditorWindow.Scale , 20 * EditorWindow.Scale,"Editor");
                if (CarbonButton(1 , 30* EditorWindow.Scale , 660* EditorWindow.Scale , 100* EditorWindow.Scale , 20* EditorWindow.Scale , 10* EditorWindow.Scale ,"Documentation" )){
                    EditorMode = 10;
                }

                CarbonPrompt(GetScreenWidth() / 2 - 150* EditorWindow.Scale , 100 * EditorWindow.Scale, 300 * EditorWindow.Scale, 100* EditorWindow.Scale , 14* EditorWindow.Scale , "Please Enter Project Folder Path" , "Folder Path");

                CarbonPrompt(GetScreenWidth() / 2 - 150* EditorWindow.Scale , 300 * EditorWindow.Scale, 300 * EditorWindow.Scale, 100* EditorWindow.Scale , 14* EditorWindow.Scale , "Please Enter Project Name" , "Project Name");
                
                CarbonButton(1 , GetScreenWidth() / 2 - 100* EditorWindow.Scale , 500* EditorWindow.Scale , 200* EditorWindow.Scale , 80* EditorWindow.Scale, 20* EditorWindow.Scale , "Create Project");

                if (CarbonButton(1 , 30* EditorWindow.Scale , 20* EditorWindow.Scale , 70* EditorWindow.Scale , 20* EditorWindow.Scale , 10* EditorWindow.Scale ,"Exit" )){
                    EditorMode = 0;
                }
                break;

            case 10:
                if (CarbonButton(1 , 30* EditorWindow.Scale , 20* EditorWindow.Scale , 70* EditorWindow.Scale , 20* EditorWindow.Scale , 10* EditorWindow.Scale ,"Back" )){
                    EditorMode = 1;
                }
                if (CarbonButton(1 , 910* EditorWindow.Scale , 20* EditorWindow.Scale , 70* EditorWindow.Scale , 20* EditorWindow.Scale , 10* EditorWindow.Scale ,"Next" )){
                    EditorMode += 1;
                }
                CarbonCenterText(100* EditorWindow.Scale , 20* EditorWindow.Scale ,"Project Creation");
                break;
        }
        if (IsKeyPressed(KEY_C) && EditorWindow.Scale >= .5f){
            EditorWindow.Scale += .5f;
            SetWindowSize(1000* EditorWindow.Scale, 700 * EditorWindow.Scale);   
        }
        if (IsKeyPressed(KEY_X) && EditorWindow.Scale >= .5f){
            EditorWindow.Scale -= .5f;
            SetWindowSize(1000* EditorWindow.Scale, 700 * EditorWindow.Scale);   
        }
		EndDrawing();
    }


    CloseWindow(); 


    return 0;
}

