#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>

#define GRID_WIDTH 10
#define GRID_HEIGHT 20

typedef enum {
    NO_SHAPE = 0,
    SHAPE_I = 1,
    SHAPE_O = 2,
    SHAPE_T = 3,
    SHAPE_L = 4,
    SHAPE_J = 5,
    SHAPE_Z = 6,
    SHAPE_S = 7,
} Shape;

typedef struct {
    bool inner[4][4];
} ShapeShape;

ShapeShape getShape(Shape shape, uint8_t rotation) {
    if (shape == SHAPE_I) {
        if (rotation == 1 || rotation == 3) {
            ShapeShape val = {
                .inner = {
                    { 1, 0, 0, 0 },
                    { 1, 0, 0, 0 },
                    { 1, 0, 0, 0 },
                    { 1, 0, 0, 0 }
                }
            };
            return val;
        } else {
            ShapeShape val = {
                .inner = {
                    { 1, 1, 1, 1 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        }
    } else if (shape == SHAPE_O) {
        ShapeShape val = {
            .inner = {
                { 1, 1, 0, 0 },
                { 1, 1, 0, 0 },
                { 0, 0, 0, 0 },
                { 0, 0, 0, 0 }
            }
        };
        return val;
    } else if (shape == SHAPE_T) {
        if (rotation == 0) {
            ShapeShape val = {
                .inner = {
                    { 1, 1, 1, 0 },
                    { 0, 1, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        } else if (rotation == 1) {
            ShapeShape val = {
                .inner = {
                    { 1, 0, 0, 0 },
                    { 1, 1, 0, 0 },
                    { 1, 0, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        } else if (rotation == 2) {
            ShapeShape val = {
                .inner = {
                    { 0, 1, 0, 0 },
                    { 1, 1, 0, 0 },
                    { 0, 1, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        } else {
            ShapeShape val = {
                .inner = {
                    { 0, 1, 0, 0 },
                    { 1, 1, 1, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        } 
    } else if (shape == SHAPE_L) {
        if (rotation == 0) {
            ShapeShape val = {
                .inner = {
                    { 1, 1, 1, 0 },
                    { 1, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        } else if (rotation == 1) {
            ShapeShape val = {
                .inner = {
                    { 1, 1, 0, 0 },
                    { 0, 1, 0, 0 },
                    { 0, 1, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        } else if (rotation == 2) {
            ShapeShape val = {
                .inner = {
                    { 0, 0, 1, 0 },
                    { 1, 1, 1, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        } else {
            ShapeShape val = {
                .inner = {
                    { 1, 0, 0, 0 },
                    { 1, 0, 0, 0 },
                    { 1, 1, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        } 
    } else if (shape == SHAPE_J) {
        if (rotation == 0) {
            ShapeShape val = {
                .inner = {
                    { 1, 1, 1, 0 },
                    { 0, 0, 1, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        } else if (rotation == 1) {
            ShapeShape val = {
                .inner = {
                    { 0, 1, 0, 0 },
                    { 0, 1, 0, 0 },
                    { 1, 1, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        } else if (rotation == 2) {
            ShapeShape val = {
                .inner = {
                    { 1, 0, 0, 0 },
                    { 1, 1, 1, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        } else {
            ShapeShape val = {
                .inner = {
                    { 1, 1, 0, 0 },
                    { 1, 0, 0, 0 },
                    { 1, 0, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        } 
    } else if (shape == SHAPE_Z) {
        if (rotation == 0 || rotation == 3) {
            ShapeShape val = {
                .inner = {
                    { 1, 1, 0, 0 },
                    { 0, 1, 1, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        } else {
            ShapeShape val = {
                .inner = {
                    { 0, 1, 0, 0 },
                    { 1, 1, 0, 0 },
                    { 1, 0, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        }
    } else if (shape == SHAPE_S) {
        if (rotation == 0 || rotation == 3) {
            ShapeShape val = {
                .inner = {
                    { 0, 1, 1, 0 },
                    { 1, 1, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        } else {
            ShapeShape val = {
                .inner = {
                    { 1, 0, 0, 0 },
                    { 1, 1, 0, 0 },
                    { 0, 1, 0, 0 },
                    { 0, 0, 0, 0 }
                }
            };
            return val;
        }
    } else {
        ShapeShape val = {
            .inner = {
                { 1, 0, 0, 0 },
                { 0, 0, 0, 0 },
                { 0, 0, 0, 0 },
                { 0, 0, 0, 0 }
            }
        };
        return val;
    }
}

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_FPoint mousepos;
    SDL_Point current;
    bool first_iteration;

    Shape grid[GRID_HEIGHT][GRID_WIDTH];

    SDL_Point shapePos;
    Shape moving;
    Shape next;
    uint8_t rotation;

    size_t delay;
} app_t;

static app_t app;

Shape randomShape(void) {
    return SDL_rand(7) + 1;
}

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
    app.window = SDL_CreateWindow(
        "Venture", 
        480,
        480,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN
    );

    SDL_SetWindowMinimumSize(app.window, 480, 480);

    // Clear grid
    SDL_memset4(&app.grid, NO_SHAPE, sizeof(app.grid));

    app.mousepos.x = -10;
    app.mousepos.y = -10;

    app.current.x = -1;
    app.current.y = -1;

    app.moving = NO_SHAPE;
    app.next = randomShape();

    app.rotation = 0;

    app.renderer = SDL_CreateRenderer(app.window, NULL);

    app.delay = 1000;

    SDL_SetRenderDrawBlendMode(app.renderer, SDL_BLENDMODE_BLEND);

    app.first_iteration = true;
    return SDL_APP_CONTINUE;
}

void drawBlock(int x, int y, Shape shape, float subSquareSize) {
    SDL_FRect iSquare = {x, y, subSquareSize, subSquareSize};
    if (shape == SHAPE_I) {
        SDL_SetRenderDrawColor(app.renderer, 0x00, 0xff, 0xff, 128);
    } else if (shape == SHAPE_O) {
        SDL_SetRenderDrawColor(app.renderer, 0xff, 0xff, 0x00, 128);
    } else if (shape == SHAPE_T) {
        SDL_SetRenderDrawColor(app.renderer, 0xff, 0x55, 0xff, 128);
    } else if (shape == SHAPE_L) {
        SDL_SetRenderDrawColor(app.renderer, 0xff, 0x55, 0x00, 128);
    } else if (shape == SHAPE_J) {
        SDL_SetRenderDrawColor(app.renderer, 0x00, 0x00, 0xff, 128);
    } else if (shape == SHAPE_Z) {
        SDL_SetRenderDrawColor(app.renderer, 0xff, 0x00, 0x00, 128);
    } else if (shape == SHAPE_S) {
        SDL_SetRenderDrawColor(app.renderer, 0x00, 0xff, 0x00, 128);
    }
    if (shape == NO_SHAPE) {
        SDL_SetRenderDrawColor(app.renderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
    } else {
        SDL_RenderFillRect(app.renderer, &iSquare);
        SDL_SetRenderDrawColor(app.renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    }
    SDL_RenderRect(app.renderer, &iSquare);
}

bool isColliding(SDL_Point shapePos, ShapeShape sh) {
    for (size_t y = 0; y < 4; y++) {
        for (size_t x = 0; x < 4; x++) {
            if (sh.inner[y][x] == false) continue;
            int rx = shapePos.x+x;
            int ry = shapePos.y+y;
            if (rx < 0) continue;
            if (ry < 0) continue;
            if (rx >= GRID_WIDTH) return true;
            if (ry >= GRID_HEIGHT) return true;
            if (app.grid[ry][rx] != NO_SHAPE) return true;
        }
    }
    return false;
}

void drawEntier(int x, int y, ShapeShape sh, Shape color, float subSquareSize) {
    for (size_t iy = 0; iy < 4; iy++) {
        for (size_t ix = 0; ix < 4; ix++) {
            if (sh.inner[iy][ix] == false) continue;
            int addx = subSquareSize*ix;
            int addy = subSquareSize*iy;
            if (addx < 0) continue;
            if (addy < 0) continue;
            drawBlock(
                x+addx,
                y+addy, 
                color, subSquareSize
            );
        }
    }
}

void pushDown(void) {
    ShapeShape sh = getShape(app.moving, app.rotation);
    SDL_Point shpos = app.shapePos;
    while (true) {
        if (isColliding(shpos, sh)) break;
        shpos.y += 1;
    }
    shpos.y -= 1;
    for (size_t y = 0; y < 4; y++) {
        for (size_t x = 0; x < 4; x++) {
            if (sh.inner[y][x] == false) continue;
            app.grid[shpos.y+y][shpos.x+x] = app.moving;
        }
    }
    app.moving = NO_SHAPE;
    app.delay -= 15;
    if (app.delay < 150) app.delay = 150;
}

void renderIngame(void) {
    int win_w = 0, win_h = 0;
    SDL_GetWindowSizeInPixels(app.window, &win_w, &win_h);
    int win_size = SDL_min(win_w, win_h); // consider the ratio of the window as 1:1

    SDL_FRect square = {0, 0, win_size/( GRID_HEIGHT / GRID_WIDTH * 1.2 ), win_size/1.2}; // 10 lines ; 20 rows
    square.x = win_w/2-(square.w/2);
    square.y = win_h/2-(square.h/2);
    SDL_FRect squareOver = {square.x-1, square.y-1, square.w+2, square.h+2};
    SDL_SetRenderDrawColor(app.renderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
    SDL_RenderRect(app.renderer, &squareOver);

    float subSquareSize = square.w/GRID_WIDTH;

    float sqx = square.x;
    float sqy = square.y;
    for (size_t x = 0; x < GRID_WIDTH; x++) {
        if (app.mousepos.x >= sqx && app.mousepos.x <= sqx+subSquareSize) {
            for (size_t y = 0; y < GRID_HEIGHT; y++) {
                if (app.mousepos.y >= sqy && app.mousepos.y <= sqy+subSquareSize) {
                    app.current.x = x;
                    app.current.y = y;
                    goto after_loop;
                }
                sqy += subSquareSize;
            }
        }
        sqy = square.y;
        sqx += subSquareSize;
    }
    app.current.x = -1;
    app.current.y = -1;
    after_loop:

    for (size_t y = 0; y < GRID_HEIGHT; y++) {
        bool block_found = false;
        for (size_t x = 0; x < GRID_WIDTH; x++) {
            if (app.grid[y][x] != NO_SHAPE) {
                block_found = true;
                drawBlock(square.x+subSquareSize*x, square.y+subSquareSize*y, app.grid[y][x], subSquareSize);
            }
        }
    }   

    if (app.moving != NO_SHAPE) {
        ShapeShape sh = getShape(app.moving, app.rotation);

        // floor projection (emulating collision)
        SDL_Point shpos = app.shapePos;
        while (true) {
            if (isColliding(shpos, sh)) break;
            shpos.y += 1;
        }
        shpos.y -= 1;
        if (!isColliding(shpos, sh)) {
            drawEntier(square.x+subSquareSize*shpos.x, square.y+subSquareSize*shpos.y, sh, NO_SHAPE, subSquareSize);
        }
        
        drawEntier(square.x+subSquareSize*app.shapePos.x, square.y+subSquareSize*app.shapePos.y, sh, app.moving, subSquareSize);

        // next piece
        drawEntier(0, 0, getShape(app.next, 0), app.next, subSquareSize);
    }

    if (app.current.x >= 0 && app.current.y >= 0) {
        SDL_FRect innerSquare = {square.x+subSquareSize*app.current.x, square.y+subSquareSize*app.current.y, subSquareSize, subSquareSize};
        SDL_SetRenderDrawColor(app.renderer, 0xff, 0x00, 0xff, SDL_ALPHA_OPAQUE);
        SDL_RenderRect(app.renderer, &innerSquare);
    }
}

bool ingameLogic(void) {
    for (size_t y = 0; y < GRID_HEIGHT; y++) {
        for (size_t x = 0; x <= GRID_WIDTH; x++) {
            if (x == GRID_WIDTH) {
                for (size_t dy = y; dy >= 1; dy--) {
                    for (size_t dx = 0; dx < GRID_WIDTH; dx++) {
                        app.grid[dy][dx] = app.grid[dy - 1][dx];
                    }
                }
                SDL_memset4(&app.grid[0], NO_SHAPE, sizeof(app.grid[0]));
                app.delay -= 40;
                if (app.delay < 150) app.delay = 150;
                break;
            } else if (app.grid[y][x] == NO_SHAPE) {
                break;
            }
        }
    }

    if (app.moving == NO_SHAPE) {
        app.moving = app.next;
        app.next = randomShape();
        app.shapePos.x = 3;
        app.shapePos.y = 0;
        if (isColliding(app.shapePos, getShape(app.moving, app.rotation))) {
            SDL_Log("game over!");
            return true;
        }
    }
    
    if (app.current.x >= 0 && app.current.y >= 0) {
        SDL_Point temp = { app.current.x, app.shapePos.y };
        if (!isColliding(temp, getShape(app.moving, app.rotation))) {
            app.shapePos = temp;
        }
    }

    static uint64_t last = 0;
    if (SDL_GetTicks() - last > app.delay) {
        last = SDL_GetTicks();
        app.shapePos.y += 1;
        if (isColliding(app.shapePos, getShape(app.moving, app.rotation))) {
            app.shapePos.y -= 1;
            pushDown();
            app.delay -= 15;
            if (app.delay < 150) app.delay = 150;
        }
    }

    return false;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    SDL_SetRenderDrawColor(app.renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(app.renderer);

    if (ingameLogic()) {
        return SDL_APP_SUCCESS;
    }
    renderIngame();

    SDL_RenderPresent(app.renderer);
    if (app.first_iteration) {
        app.first_iteration = false;
        SDL_ShowWindow(app.window);
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    if (event->type == SDL_EVENT_MOUSE_MOTION) {
        app.mousepos.x = event->motion.x;
        app.mousepos.y = event->motion.y;
    } else if (event->type == SDL_EVENT_WINDOW_MOUSE_LEAVE) {
        app.mousepos.x = -10;
        app.mousepos.y = -10;
    } else if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        if (event->button.button == 1  || event->button.button == 3) { // push down
            pushDown();
        }
    } else if (event->type == SDL_EVENT_MOUSE_WHEEL) {
        uint8_t prev = app.rotation;
        if (app.rotation == 0) {
            if (event->wheel.y > 0) {
                app.rotation = 1;
            } else if (event->wheel.y < 0) {
                app.rotation = 3;
            }
        } else if (app.rotation == 3) {
            if (event->wheel.y > 0) {
                app.rotation = 0;
            } else if (event->wheel.y < 0) {
                app.rotation = 2;
            }
        } else {
            if (event->wheel.y > 0) {
                app.rotation += 1;
            } else if (event->wheel.y < 0) {
                app.rotation -= 1;
            }
        }
        if (isColliding(app.shapePos, getShape(app.moving, app.rotation))) {
            app.rotation = prev;
        }
    } else if (event->type == SDL_EVENT_WINDOW_RESIZED) {
        renderIngame();
    } else if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
}
