#include <cstdlib>
#include "raylib.h"
#include "particle.h"
#include "constants.h"
#include <vector>
#include <iostream>

using namespace std;

// variables
Color grey = {100,29,27,255};
vector<Particle> particles;

int main() {
    InitWindow(WIDTH, HEIGHT, "SPACE INVADERS");
    SetTargetFPS(60);

    for (int i = 0; i < 100; i++) {
        particles.push_back(Particle(WIDTH, HEIGHT));
    }

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();


        BeginDrawing();
        ClearBackground(WHITE);

        for (auto &p : particles) {
            p.draw();
            p.update(WIDTH, HEIGHT, dt);
            p.attractToCursor({GetMousePosition()},dt);
        }


        EndDrawing();
    }

    CloseWindow();
    return 0;
}