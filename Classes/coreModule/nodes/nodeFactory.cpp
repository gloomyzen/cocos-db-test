#include "nodeFactory.h"
#include <map>
#include <string>
#include "debugModule/logManager.h"
#include "ui/CocosGUI.h"

using namespace mb::coreModule;
using namespace cocos2d;
using namespace cocos2d::ui;

std::map<std::string, eNodeFactory> componentsMap = {
		{"TransformComponent",  eNodeFactory::TRANSFORM_COMPONENT},
		{"SpriteComponent",     eNodeFactory::SPRITE_COMPONENT},
		{"AnimspriteComponent", eNodeFactory::ANIMSPRITE_COMPONENT},
};
std::map<std::string, std::function<Node*()>> nodes{};

nodeFactory *currentNodeFactory = nullptr;

nodeFactory::nodeFactory() {
	if (!inited) {
		inited = true;
		nodes["node"] = []()->Node* { return new Node(); };
		nodes["sprite"] = []()->Sprite* { return new Sprite(); };
		nodes["pageView"] = []()->PageView* { return new PageView(); };
	}
}

nodeFactory::~nodeFactory() = default;

nodeFactory &nodeFactory::getInstance() {
	if (currentNodeFactory == nullptr) {
		currentNodeFactory = new nodeFactory();
	}
	return *currentNodeFactory;
}

void nodeFactory::getComponents(Node *node, const std::string &componentName,const rapidjson::GenericValue<rapidjson::UTF8<char>>::Object &object) {
	if (node == nullptr)
		return;

	if (!hasRegisteredComponent(componentName)) {
		LOG_ERROR("nodeFactory::getComponents: Component '" + componentName + "' was not found!");
		return;
	}

	eNodeFactory needle = componentsMap[componentName];

	switch (needle) {
		case TRANSFORM_COMPONENT: {
			if (object.HasMember("position")) {
				auto positions = object["position"].GetArray();
				if (positions.Size() == 2) {
					node->setPosition(positions[0].GetFloat(), positions[1].GetFloat());
				} else {
					LOG_ERROR("nodeFactory::getComponents: Component: '" + componentName + "' has '" +
							  std::to_string(positions.Size()) + "' position keys!");
				}
			}
			if (object.HasMember("size")) {
				auto size = object["size"].GetArray();
				if (size.Size() == 2) {
					auto _size = cocos2d::Size();
					_size.width = size[0].GetFloat();
					_size.height = size[1].GetFloat();
					node->setContentSize(_size);
				} else {
					LOG_ERROR("nodeFactory::getComponents: Component '" + componentName + "' has '" +
							  std::to_string(size.Size()) + "' size keys!");
				}
			}
			if (object.HasMember("scale") && object["scale"].IsNumber()) {
				//todo
			}
		}
			break;
		case SPRITE_COMPONENT: {
			if (auto sprite = dynamic_cast<Sprite*>(node)) {
				if (object.HasMember("image") && object["image"].IsString()) {
					sprite->initWithFile(object["image"].GetString());
				}
			} else {
				LOG_ERROR("nodeFactory::getComponents: Component '" + componentName + "' no has sprite node type!");
			}
		}
			break;
//		case ANIMSPRITE_COMPONENT:
//			node->addComponent<SpriteComponent>();
//			break;
		case ANIMSPRITE_COMPONENT:
			break;
	}
}

bool nodeFactory::hasRegisteredComponent(const std::string &componentName) {
	return (componentsMap.find(componentName) != componentsMap.end());
}

Node *nodeFactory::createNodeWithType(const std::string &type) {
	if (nodes.count(type)) {
		return nodes[type]();
	}
	LOG_ERROR("nodeFactory::createNodeWithType: Type of node '" + type + "' not registered! Created simple node.");
	return Node::create();
}

void nodeFactory::init() {

}
