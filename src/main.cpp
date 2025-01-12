#include <cstdio>
#include <raylib.h>

int main(int argc, char** argv) {
    TraceLog(LOG_NONE, "The start of something great");
    const int width = 1280;
    const int height = 720;
    const int init_flags = FLAG_MSAA_4X_HINT; // some flags can't be changed at runtime, so have them separate and const
    int flags = FLAG_VSYNC_HINT|FLAG_WINDOW_RESIZABLE;
    SetConfigFlags(init_flags|flags);
    InitWindow(width, height, "term - gpu");
    SetTraceLogLevel(LOG_WARNING);
    bool running = true;
    while (running) {
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

        Vector2 triangle_pos[] = {
            Vector2{width / 2, height - (height / 3)*2},
            Vector2{width / 3, height - (height / 3)},
            Vector2{width - width / 3, height - (height / 3)},
        };

        BeginDrawing();
        ClearBackground(BLACK);

        // printf("0: (%.1f,%.1f), 1: (%.1f,%.1f) 2: (%.1f,%.1f)\n", triangle_pos[0].x, triangle_pos[0].y, triangle_pos[1].x, triangle_pos[1].y, triangle_pos[2].x, triangle_pos[2].y);
        DrawTriangle(triangle_pos[0], triangle_pos[1], triangle_pos[2], BLUE);
        DrawText(TextFormat("%d", GetFPS()), 4, 4, 16, WHITE);
        EndDrawing();


    }
    CloseWindow();

}
