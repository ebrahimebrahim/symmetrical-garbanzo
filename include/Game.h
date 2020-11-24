#ifndef GAME_H
#define GAME_H

#include <GameWindow.h>
#include <memory>
#include <vector>
#include <Entity.h>
#include <Camera.h>
#include <Player.h>
#include <level_gen.h>

/**
    The game loop
*/

class Game {

    /** Handle user input in the game loop */
    void handle_input();

    /** Render game state into framebuffer and swap buffers */
    void render();
    
    /** Time spent on the last frame of rendering, in seconds. */
    double last_frame_time{};

    /** Mouse movement vector on the last frame of rendering */
    glm::vec2 last_frame_mouse_delta{0.0f,0.0f};

    std::unique_ptr<GameWindow> window;
    std::vector<std::unique_ptr<Entity>> entities;
    std::unique_ptr<Camera> camera;
    Player * player{}; /** handle to player, which is a regular entity that should be in the std::vector of entities */
    LevelGen::Tilemap level;

public:
    /** Run the game, returning return code on exit. 0 means no errors. */
    int run();

    /** Fixed update step size in seconds, for deterministic updates to game state */
    const double time_per_update{0.016666667};

    /** Get current game fps */
    double getFPS() {return 1.0/last_frame_time;}

    bool quit = false;

};

#endif // GAME_H