#ifndef SEContainerFILE
#define SEContainerFILE

#include "EnemiesContainer.h"
#include "ShootyEnemy.h"
#include "EBulletContainer.h"


class ShootyEnemyContainer : public EnemiesContainer
{
public:
    ShootyEnemyContainer();
    ~ShootyEnemyContainer() override;
    void Update() override;
    void Add() override;

    EBulletContainer* bulletContainer;
};
#endif
