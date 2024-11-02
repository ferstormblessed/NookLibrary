//
// Created by stormblessed on 9/4/24.
//

#pragma once

#include "NOOK/components/IntVariableDebug.h"
#include "NOOK/components/FloatVariableDebug.h"
#include "NOOK/components/BoolVariableDebug.h"
#include "NOOK/Systems/Render/RenderShapeSystem.h"
#include "NOOK/Systems/Render/RenderTextSystem.h"
#include "NOOK/Systems/Render/RenderSpriteSystem.h"
#include "NOOK/Systems/Physics/PhysicsSystem.h"
#include "NOOK/Systems/Movement/MovementSystem.h"
#include "NOOK/Systems/Movement/JumpSystem.h"
#include "NOOK/Systems/GameLogic/GameLogicSystem.h"
#include "NOOK/Systems/GameLogic/PauseSystem.h"
#include "NOOK/Systems/GameLogic/GameOverSystem.h"
#include "NOOK/Systems/Debug/DebugSystem.h"


namespace NOOK {

    void registerComponents();
    std::shared_ptr<NOOK::RenderShapeSystem> registerRenderShapeSystem();
    std::shared_ptr<NOOK::RenderTextSystem> registerRenderTextSystem();
    std::shared_ptr<NOOK::RenderSpriteSystem> registerRenderSpriteSystem();
    std::shared_ptr<NOOK::PhysicsSystem> registerPhysicsSystem();
    std::shared_ptr<NOOK::MovementSystem> registerMovementSystem();
    std::shared_ptr<NOOK::JumpSystem> registerJumpSystem();
    std::shared_ptr<NOOK::GameLogicSystem> registerGameLogicSystem();
    std::shared_ptr<NOOK::PauseSystem> registerPauseSystem();
    std::shared_ptr<NOOK::GameOverSystem> registerGameOverSystem();
    std::shared_ptr<NOOK::DebugSystem> registerDebugSystem();

} // NAMESPACE NOOK