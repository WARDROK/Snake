#pragma once

#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Game.hpp"

class PauseGame : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_pauseTitle;

public:
    PauseGame(std::shared_ptr<Context>& context);
    ~PauseGame();

    virtual void Init() override;
    virtual void ProcessInput() override;
    virtual void Update(sf::Time deltaTime) override;
    virtual void Draw() override;
};