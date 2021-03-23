#include "battleField.h"
#include "common/coreModule/nodes/widgets/node3d.h"

using namespace mb::battleModule;

battleField::battleField() {}

void battleField::loadLocation(const std::string& name) {
    // load json
    const std::string& regionStr = cocos2d::FileUtils::getInstance()->getStringFromFile("properties/nodeProperties/battle/themes/locations.json");
    rapidjson::Document doc;
    doc.Parse<0>(regionStr.c_str());

    if (doc.HasParseError() || doc.IsNull() || !doc.IsObject()) {
        LOG_ERROR("battleField::loadLocation: json parse error");
        return;
    }
    if (!doc.HasMember(name.c_str()) || !doc[name.c_str()].IsObject()) {
        LOG_ERROR(STRING_FORMAT("battleField::loadLocation: location '%s' not found or object is not valid!", name.c_str()));
        return;
    }
    auto data = doc[name.c_str()].GetObjectJ();
    setName(STRING_FORMAT("battlefield_%s", name.c_str()));
    if (data.HasMember("sky") && data["sky"].IsString()) {
        auto sky = new cocos2d::Node();
        sky->setName("sky");
        loadProperty(data["sky"].GetString(), sky);
        addChild(sky);
    }
    cocos2d::Node* node = this;
    if (data.HasMember("ground") && data["ground"].IsString()) {
        auto ground = new cocos2d::Node();
        ground->setName("ground");
        loadProperty(data["ground"].GetString(), ground);
        addChild(ground);
        node = ground;
    }
    if (data.HasMember("base") && data["base"].IsString()) {
        baseNode = new common::coreModule::node3d();
        baseNode->setName("base");
        loadProperty(data["base"].GetString(), baseNode);
        node->addChild(baseNode);
    } else {
        LOG_ERROR(STRING_FORMAT("battleField::loadLocation: location '%s': base node not exist!", name.c_str()));
        return;
    }
}
