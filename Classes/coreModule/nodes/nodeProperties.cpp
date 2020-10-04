#include "nodeProperties.h"
#include "coreModule/resources/resourceManager.h"

using namespace mercenaryBattles::coreModule;
using namespace cocos2d;
using namespace rapidjson;


void nodeProperties::loadProperty(const std::string &path, Node *node) {
	if (this->getName().empty()) {
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

	//TODO if json["name"].GetString() == this->getName() -> read like this node
	//TODO if json["name"].GetString() != this->getName() -> read like child node
//	if (json["name"].GetString() != this->getName()) {
//		LOG_ERROR("Node::loadProperty Node id: '" + static_cast<std::string>(json["name"].GetString()) +
//				  "' and this->getName() '" + this->getName() + "' is not match!");
//		return;
//	}

//	if (json.HasMember("childs") && json["childs"].IsArray()) {
//		parseData(this, json["childs"].GetArray());
//	}
//
//	parseProperty(this, pathProperties, prefix);
}

void nodeProperties::parseData(Node *node, const GenericValue<UTF8<char>>::Array &array) {
	for (auto &item : array) {
		if (item["type"].IsString() && item["name"].IsString()) {
			auto childNode = Node::create();
			childNode->setName(item["name"].GetString());
			if (item.HasMember("childs")) {
				parseData(childNode, item["childs"].GetArray());
			}
			node->addChild(childNode);
		}
	}
}

//todo add parseProperty
