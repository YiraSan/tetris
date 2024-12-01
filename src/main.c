#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>

typedef struct {
    
} appstate_t;


SDL_AppResult SDL_AppInit(void **as, int argc, char **argv) {
    *as = SDL_malloc(sizeof(appstate_t));
    appstate_t *appstate = (appstate_t*) as;

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *as) {
    appstate_t *appstate = (appstate_t*) as;

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *as, SDL_Event *event) {
    appstate_t *appstate = (appstate_t*) as;

    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *as, SDL_AppResult result) {
    appstate_t *appstate = (appstate_t*) as;

    SDL_free(appstate);
}
