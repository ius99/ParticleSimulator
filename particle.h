#ifndef UNTITLED1_PARTICLE_H
#define UNTITLED1_PARTICLE_H
#include <stdlib.h>
#include <math.h>
#include "raylib.h"
#include <vector>
#include "constants.h"
using namespace std;

class Particle {
private:
    Vector2 position;
    Vector2 velocity;
    Color color;

    float getDist(Vector2 other) {
        float dx = other.x - position.x;
        float dy = other.y - position.y;
        return sqrtf(dx*dx + dy*dy);
    }

    Vector2 getNormal(Vector2 other) {
        float d = getDist(other);
        if (d == 0) return {0, 0};
        return { (other.x - position.x) / d, (other.y - position.y) / d };
    }

public:
    Particle(int WIDTH, int HEIGHT) {
        position.x = GetRandomValue(0, WIDTH - 1);
        position.y = GetRandomValue(0, HEIGHT - 1);
        velocity.x = GetRandomValue(-500, 500) / 10.0f; // -50 to 50
        velocity.y = GetRandomValue(-500, 500) / 10.0f;
        int r = GetRandomValue(0, 255);
        int g = GetRandomValue(0, 255);
        int b = GetRandomValue(0, 255);

        color = {(unsigned char)r,(unsigned char)g,(unsigned char)b,255 };

    }

    void draw() {
        DrawCircle(position.x, position.y,5, color);

    }

    void update(int WIDTH, int HEIGHT, float dt) {
        static int updateCount = 0;
        updateCount++;
        position.x += velocity.x * dt;
        position.y += velocity.y * dt;
        if (position.x <= 0) {
            position.x = 0;
            velocity.x = abs(velocity.x);
        } else if (position.x >= WIDTH) {
            position.x = WIDTH;
            velocity.x = -abs(velocity.x);
        }

        if (position.y <= 0) {
            position.y = 0;
            velocity.y = abs(velocity.y);
        } else if (position.y >= HEIGHT) {
            position.y = HEIGHT;
            velocity.y = -abs(velocity.y);
        }
    }

    void attractToCursor(Vector2 mousePos, float dt) {
        float dist = getDist(mousePos);
        if (dist < 300) {
            Vector2 direction = getNormal(mousePos);
            float attractionStrength = 1700.0f;
            float force = attractionStrength / (dist + 1);
            velocity.x += direction.x * force * dt;
            velocity.y += direction.y * force * dt;
            velocity.x *= 0.99f;
            velocity.y *= 0.99f;
        }
    }



};

#endif