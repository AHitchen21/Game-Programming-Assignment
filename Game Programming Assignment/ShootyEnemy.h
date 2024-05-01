#ifndef ShootyEnemiesFILE
#define ShootyEnemiesFILE

#include "Enemies.h"
#include "SDL.h"

class EBulletContainer;

class ShootyEnemy : public Enemies
{
public:
    ShootyEnemy();
    ~ShootyEnemy() override;
    void Update(int screenX, int screenY) override;

    EBulletContainer* child;
};
#endif
