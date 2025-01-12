#include <cstdio>
#include <raylib.h>

void draw_frame() {
    DrawText(TextFormat("%d", GetFPS()), 20, 20, 40, RED);
    DrawText(TextFormat("%d", 123456789), 20, 70, 40, RED);
    // DrawTriangle(Vector2{1600,800}, Vector2{300,300}, Vector2{200,400}, YELLOW);
}

int main(int argc, char** argv) {
    float content_scale = 10.0f;
    TraceLog(LOG_NONE, "The start of something great");
    const int width = 1280;
    const int height = 720;
    const int init_flags = FLAG_MSAA_4X_HINT; // some flags can't be changed at runtime, so have them separate and const
    int flags = FLAG_VSYNC_HINT|FLAG_WINDOW_RESIZABLE;
    SetConfigFlags(init_flags|flags);
    InitWindow(width, height, "term - gpu");
    SetTraceLogLevel(LOG_WARNING);
    bool running = true;
    RenderTexture2D main_rt = LoadRenderTexture(GetRenderWidth(), GetRenderHeight());
    Rectangle window_rect = {0,0,0,0};

    // try shell here I guess

    while (running) {
        // could move to if resized to save some performance
        window_rect = Rectangle{0.0f, 0.0f, (float)GetRenderWidth(), (float)GetRenderHeight()};
        if (IsWindowResized()) {
            UnloadRenderTexture(main_rt);
            main_rt = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
        }
        if (WindowShouldClose()) {
            running = false;
        }
        if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_Q)) {
            running = false;
        }
        if (IsKeyPressed(KEY_C)) {
            ClearWindowState(flags);
        }

        if (IsKeyPressed(KEY_V)) {
            SetWindowState(flags);
        }

        BeginDrawing();
        ClearBackground(BLACK);

        BeginTextureMode(main_rt);
        ClearBackground(BLACK);
        draw_frame();
        EndTextureMode();

        DrawTexturePro(main_rt.texture, Rectangle{0,0,(float)main_rt.texture.width,(float)-main_rt.texture.height}, window_rect, Vector2{0.0f,0.0f}, 0.0f, WHITE);

        EndDrawing();
    }
    CloseWindow();
}
