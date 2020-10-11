#include "nodeProperties.h"
#include "coreModule/resources/resourceManager.h"
#include "coreModule/nodes/nodeFactory.h"
#include "coreModule/gameManager.h"

using namespace mb::coreModule;
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
		usedNode = GET_NODE_FACTORY().createNodeWithType(json["type"].GetString());
		usedNode->setName(json["name"].GetString());
		node->addChild(usedNode);
	} else {
		usedNode = node;
	}

	if (json.HasMember("child") && json["child"].IsArray()) {
		parseData(usedNode, json["child"].GetArray());
	}

	parseComponents(usedNode, pathProperties, true);
}

void nodeProperties::parseData(Node *node, const GenericValue<UTF8<char>>::Array &array) {
	for (auto &item : array) {
		if (item["type"].IsString() && item["name"].IsString()) {
			auto childNode = GET_NODE_FACTORY().createNodeWithType(item["type"].GetString());
			childNode->setName(item["name"].GetString());
			if (item.HasMember("child")) {
				parseData(childNode, item["child"].GetArray());
			}
			node->addChild(childNode);
		}
	}
}

void nodeProperties::parseComponents(Node *node, const std::string &pathProperties, bool recursive) {
	auto propJson = GET_JSON(pathProperties);

	if (propJson.HasParseError() || !propJson.IsObject()) {
		LOG_ERROR("nodeProperties::parseProperty Json file '" + pathProperties + "' has errors or not found!");
		return;
	}
	bool found = false;
	for (auto &propList : propJson.GetObject()) {
		auto nodeName = propList.name.GetString();
		if (!recursive && nodeName != node->getName()) {
			continue;
		} else if (!recursive && nodeName == node->getName()) {
			found = true;
		}
		if (!propJson[nodeName].IsObject()) {
			continue;
		}
		auto *targetNode = findNode(nodeName, node);
		if (targetNode == nullptr) continue;

		for (const auto &component : componentPriorityList) {
			if (component.empty()) {
				LOG_ERROR(StringUtils::format("nodeProperties::parseProperty bad property '%s' in 'componentPriorityList'", component.c_str()));
				continue;
			}
			const auto componentItr = propJson[nodeName].FindMember(component.c_str());
			if(componentItr != propJson[nodeName].MemberEnd()) {
				if (componentItr->value.IsObject()) {
					GET_NODE_FACTORY().getComponents(targetNode, component, componentItr->value.GetObject());
				}
			}
		}
//
//		const auto transformComponentItr = propJson[nodeName].FindMember("TransformComponent");
//		if(transformComponentItr != propJson[nodeName].MemberEnd()) {
//			const std::string componentName = transformComponentItr->name.GetString();
//			if (transformComponentItr->value.IsObject()) {
//				GET_NODE_FACTORY().getComponents(targetNode, componentName, transformComponentItr->value.GetObject());
//			}
//		}
//		const auto spriteComponentItr = propJson[nodeName].FindMember("SpriteComponent");
//		if(spriteComponentItr != propJson[nodeName].MemberEnd()) {
//			const std::string componentName = spriteComponentItr->name.GetString();
//			if (spriteComponentItr->value.IsObject()) {
//				GET_NODE_FACTORY().getComponents(targetNode, componentName, spriteComponentItr->value.GetObject());
//			}
//		}
//		const auto labelComponentItr = propJson[nodeName].FindMember("LabelComponent");
//		if(labelComponentItr != propJson[nodeName].MemberEnd()) {
//			const std::string componentName = labelComponentItr->name.GetString();
//			if (labelComponentItr->value.IsObject()) {
//				GET_NODE_FACTORY().getComponents(targetNode, componentName, labelComponentItr->value.GetObject());
//			}
//		}
//		for (auto &item : propJson[nodeName].GetObject()) {
//			const std::string componentName = item.name.GetString();
//			if (item.value.IsObject()) {
//				GET_NODE_FACTORY().getComponents(targetNode, componentName, item.value.GetObject());
//			}
//		}
		if (found && !recursive) {
			return;
		}
	}
}
