#ifndef SEContainerFILE
#define SEContainerFILE

#include "EnemiesContainer.h"
#include "ShootyEnemy.h"
#include "EBulletContainer.h"
#include "SDL.h"

class ShootyEnemyContainer : public EnemiesContainer
{
public:
    ShootyEnemyContainer();
    ~ShootyEnemyContainer() override;
    void Update(SDL_Renderer* renderer) override;
    void Add(SDL_Renderer* renderer) override;

    EBulletContainer* bulletContainer;
};
#endif
