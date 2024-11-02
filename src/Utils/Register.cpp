//
// Created by stormblessed on 11/2/24.
//

#include "NOOK/Utils/Register.h"
#include "NOOK/core/Coordinator.h"
#include "NOOK/components/PhysicsCircle.h"
#include "NOOK/components/PhysicsPolygon.h"
#include "NOOK/components/CircleShape.h"
#include "NOOK/components/PlayerMove.h"
#include "NOOK/components/RectangleShape.h"
#include "NOOK/components/RigidBody.h"
#include "NOOK/components/Shape.h"
#include "NOOK/components/Sprite.h"
#include "NOOK/components/Text.h"
#include "NOOK/components/Transform.h"
#include "NOOK/components/Logic.h"
#include "NOOK/components/Jump.h"
#include "NOOK/components/Pause.h"
#include "NOOK/components/GameOver.h"
#include "NOOK/components/Debug.h"

extern NOOK::Coordinator gCoordinator;

namespace NOOK {

    void registerComponents() {
        gCoordinator.registerComponent<NOOK::PhysicsCircle>();
        gCoordinator.registerComponent<NOOK::PhysicsPolygon>();
        gCoordinator.registerComponent<NOOK::CircleShape>();
        gCoordinator.registerComponent<NOOK::PlayerMove>();
        gCoordinator.registerComponent<NOOK::RectangleShape>();
        gCoordinator.registerComponent<NOOK::RigidBody>();
        gCoordinator.registerComponent<NOOK::Shape>();
        gCoordinator.registerComponent<NOOK::Sprite>();
        gCoordinator.registerComponent<NOOK::Text>();
        gCoordinator.registerComponent<NOOK::Transform>();
        gCoordinator.registerComponent<NOOK::Logic>();
        gCoordinator.registerComponent<NOOK::Jump>();
        gCoordinator.registerComponent<NOOK::Pause>();
        gCoordinator.registerComponent<NOOK::GameOver>();
        gCoordinator.registerComponent<NOOK::Debug>();
        gCoordinator.registerComponent<NOOK::IntVariableDebug>();
        gCoordinator.registerComponent<NOOK::FloatVariableDebug>();
        gCoordinator.registerComponent<NOOK::BoolVariableDebug>();
    }

    std::shared_ptr<NOOK::RenderShapeSystem> registerRenderShapeSystem() {
        auto renderShapeSystem = gCoordinator.registerSystem<NOOK::RenderShapeSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Shape>());
            signature.set(gCoordinator.getComponentType<NOOK::Transform>());
            gCoordinator.setSystemSignature<NOOK::RenderShapeSystem>(signature);
        }
        return renderShapeSystem;
    }

    std::shared_ptr<NOOK::RenderTextSystem> registerRenderTextSystem() {
        auto renderTextSystem = gCoordinator.registerSystem<NOOK::RenderTextSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Text>());
            signature.set(gCoordinator.getComponentType<NOOK::Transform>());
            gCoordinator.setSystemSignature<NOOK::RenderTextSystem>(signature);
        }
        return renderTextSystem;
    }

    std::shared_ptr<NOOK::RenderSpriteSystem> registerRenderSpriteSystem() {
        auto renderSystem = gCoordinator.registerSystem<NOOK::RenderSpriteSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Sprite>());
            signature.set(gCoordinator.getComponentType<NOOK::Transform>());
            gCoordinator.setSystemSignature<NOOK::RenderSpriteSystem>(signature);
        }
        return renderSystem;
    }

    std::shared_ptr<NOOK::PhysicsSystem> registerPhysicsSystem() {
        auto physicsSystem = gCoordinator.registerSystem<NOOK::PhysicsSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::RigidBody>());
            gCoordinator.setSystemSignature<NOOK::PhysicsSystem>(signature);
        }
        return physicsSystem;
    }

    std::shared_ptr<NOOK::MovementSystem> registerMovementSystem() {
        auto movementSystem = gCoordinator.registerSystem<NOOK::MovementSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::PlayerMove>());
            signature.set(gCoordinator.getComponentType<NOOK::RigidBody>());
            gCoordinator.setSystemSignature<NOOK::MovementSystem>(signature);
        }
        return movementSystem;
    }

    std::shared_ptr<NOOK::JumpSystem> registerJumpSystem() {
        auto jumpSystem = gCoordinator.registerSystem<NOOK::JumpSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Jump>());
            signature.set(gCoordinator.getComponentType<NOOK::RigidBody>());
            gCoordinator.setSystemSignature<NOOK::JumpSystem>(signature);
        }
        return jumpSystem;
    }

    std::shared_ptr<NOOK::GameLogicSystem> registerGameLogicSystem() {
        auto gameLogicSystem = gCoordinator.registerSystem<NOOK::GameLogicSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Logic>());
            gCoordinator.setSystemSignature<NOOK::GameLogicSystem>(signature);
        }
        return gameLogicSystem;
    }

    std::shared_ptr<NOOK::PauseSystem> registerPauseSystem() {
        auto pauseSystem = gCoordinator.registerSystem<NOOK::PauseSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Pause>());
            gCoordinator.setSystemSignature<NOOK::PauseSystem>(signature);
        }
        return pauseSystem;
    }

    std::shared_ptr<NOOK::GameOverSystem> registerGameOverSystem() {
        auto gameOverSystem = gCoordinator.registerSystem<NOOK::GameOverSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::GameOver>());
            gCoordinator.setSystemSignature<NOOK::GameOverSystem>(signature);
        }
        return gameOverSystem;
    }

    std::shared_ptr<NOOK::DebugSystem> registerDebugSystem() {
        auto debugSystem = gCoordinator.registerSystem<NOOK::DebugSystem>();
        {
            NOOK::Signature signature;
            signature.set(gCoordinator.getComponentType<NOOK::Debug>());
            gCoordinator.setSystemSignature<NOOK::DebugSystem>(signature);
        }
        return debugSystem;
    }

} // NAMESPACE NOOK
