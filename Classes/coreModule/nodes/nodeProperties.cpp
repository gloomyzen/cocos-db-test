#include "nodeProperties.h"
#include "coreModule/resources/resourceManager.h"

using namespace mercenaryBattles::coreModule;


void nodeProperties::loadProperty(const std::string &path, cocos2d::Node *node) {
	if (getId().empty()) {
		LOG_ERROR("Node::loadProperty Node has no identifier!");
		return;
	}
	std::string pathNodes = "nodes/" + path;
	std::string pathProperties = "properties/" + path;

	auto json = GET_JSON(pathNodes);
	if (json.HasParseError() || !json.IsObject()) {
		LOG_ERROR("Node::loadProperty Json file '" + pathNodes + "' is not valid!");
		return;
	}
	if (!json.HasMember("type") || !json.HasMember("name") || !json["type"].IsString() || !json["name"].IsString()) {
		LOG_ERROR("Node::loadProperty Json file '" + pathNodes + "' not has 'type' and 'name'!");
		return;
	}

	if (json["name"].GetString() != getId()) {
		LOG_ERROR("Node::loadProperty Node id: '" + static_cast<std::string>(json["name"].GetString()) +
				  "' and getId() '" + getId() + "' is not match!");
		return;
	}
}
