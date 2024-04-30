#ifndef ShootyEnemiesFILE
#define ShootyEnemiesFILE

#include "Enemies.h"

class ShootyEnemy : public Enemies
{
public:
    ShootyEnemy();
    ~ShootyEnemy() override;
    void Update(int screenX, int screenY) override;
};
#endif
