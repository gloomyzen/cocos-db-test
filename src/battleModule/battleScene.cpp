#include "battleScene.h"

using namespace mb::battleModule;
using namespace cocos2d;

battleScene::battleScene() {
    this->setName("battleScene");
    loadProperty("scenes/" + this->getName(), dynamic_cast<Node*>(this));
}

std::deque<nodeTasks> battleScene::getTasks() {
    std::deque<nodeTasks> result;

    result.emplace_back([this]() {
        //------------ player base
//        auto billboard = dynamic_cast<Sprite*>(findNode("ground"));
//
//        billboard->setRotation3D(cocos2d::Vec3(-50.f, 0.f, 0.f));
//        auto anim = dynamic_cast<Node*>(findNode("anim"));
//        anim->setRotation3D(cocos2d::Vec3(50.f, 0.f, 0.f));
//        auto anim2 = dynamic_cast<Node*>(findNode("anim2"));
//        anim2->setRotation3D(cocos2d::Vec3(50.f, 0.f, 0.f));

        return eTasksStatus::STATUS_OK;
    });

    return result;
}
