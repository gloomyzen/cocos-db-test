#include "battleField.h"

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
        loadProperty(data["sky"].GetString(), sky);
        addChild(sky);
    }
    if (data.HasMember("ground") && data["ground"].IsString()) {
        auto ground = new cocos2d::Node();
        loadProperty(data["ground"].GetString(), ground);
        addChild(ground);
    }
    if (data.HasMember("base") && data["base"].IsString()) {
        baseNode = new cocos2d::Node();
        loadProperty(data["base"].GetString(), baseNode);
        addChild(baseNode);
    } else {
        LOG_ERROR(STRING_FORMAT("battleField::loadLocation: location '%s': base node not exist!", name.c_str()));
        return;
    }
}
