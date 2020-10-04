#include "nodeProperties.h"
#include "coreModule/resources/resourceManager.h"

using namespace mercenaryBattles::coreModule;
using namespace cocos2d;
using namespace rapidjson;


void nodeProperties::loadProperty(const std::string &path, Node *node) {
	if (node->getName().empty()) {
		LOG_ERROR("Node::loadProperty Node has no identifier!");
		return;
	}
	std::string pathNodes = "nodes/" + path;
	std::string pathProperties = "properties/" + path;

	auto json = GET_JSON(pathNodes);
	if (json.HasParseError() || !json.IsObject()) {
		LOG_ERROR("nodeProperties::loadProperty Json file '" + pathNodes + "' has erroes or not found!");
		return;
	}
	if (!json.HasMember("type") || !json.HasMember("name") || !json["type"].IsString() || !json["name"].IsString()) {
		LOG_ERROR("nodeProperties::loadProperty Json file '" + pathNodes + "' not has 'type' and 'name'!");
		return;
	}

	/// If the first named element is different from the current node, add the new node as a child to the current node
	Node* usedNode;
	if (json["name"].GetString() != this->getName()) {
		usedNode = Node::create();
		node->addChild(usedNode);
	} else {
		usedNode = node;
	}

	if (json.HasMember("child") && json["child"].IsArray()) {
		parseData(usedNode, json["child"].GetArray());
	}

	parseProperty(usedNode, pathProperties);
}

void nodeProperties::parseData(Node *node, const GenericValue<UTF8<char>>::Array &array) {
	for (auto &item : array) {
		if (item["type"].IsString() && item["name"].IsString()) {
			auto childNode = Node::create();
			childNode->setName(item["name"].GetString());
			if (item.HasMember("child")) {
				parseData(childNode, item["child"].GetArray());
			}
			node->addChild(childNode);
		}
	}
}

void nodeProperties::parseProperty(Node *node, const std::string &pathProperties) {
	auto propJson = GET_JSON(pathProperties);

	if (propJson.HasParseError() || !propJson.IsObject()) {
		LOG_ERROR("nodeProperties::parseProperty Json file '" + pathProperties + "' has errors or not found!");
		return;
	}

	for (auto &propList : propJson.GetObject()) {
		auto nodeName = propList.name.GetString();

		if (!propJson[nodeName].IsObject()) {
			continue;
		}
//		auto *targetNode = node->findNode(nodeName);
		for (auto &item : propJson[nodeName].GetObject()) {
			std::string componentName = item.name.GetString();
			if (item.value.IsObject()) {
//				NodeFactory::getComponents(targetNode, componentName, item.value.GetObject());
			}
		}

	}
}

//todo add parseProperty
