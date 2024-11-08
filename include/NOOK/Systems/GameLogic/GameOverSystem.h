//
// Created by stormblessed on 10/27/24.
//

#ifndef NOOK_GAMEOVERSYSTEM_H
#define NOOK_GAMEOVERSYSTEM_H

#include "NOOK/core/System.h"

namespace NOOK {

    class GameOverSystem : public System {
    public:
        void init();
        void update(GAME_STATE& gameState);
    };


} // NAMESPACE NOOK

#endif //NOOK_GAMEOVERSYSTEM_H
