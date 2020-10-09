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
		{"LabelComponent", eNodeFactory::LABEL_COMPONENT},
};
std::map<std::string, std::function<Node*()>> nodes{};

nodeFactory *currentNodeFactory = nullptr;

nodeFactory::nodeFactory() {
	if (!inited) {
		inited = true;
		nodes["node"] = []()->Node* { return new Node(); };
		nodes["sprite"] = []()->Sprite* { return new Sprite(); };
		nodes["label"] = []()->Label* { return new Label(); };
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
					LOG_ERROR(StringUtils::format("nodeFactory::getComponents: Component '%s' has '%s' position keys!",
												  componentName.c_str(), std::to_string(positions.Size()).c_str()));
				}
			}
			if (object.HasMember("anchor")) {
				auto anchor = object["anchor"].GetArray();
				if (anchor.Size() == 2) {
					node->setAnchorPoint(Vec2(anchor[0].GetFloat(), anchor[1].GetFloat()));
				} else {
					LOG_ERROR(StringUtils::format("nodeFactory::getComponents: Component '%s' has '%s' anchor keys!",
												  componentName.c_str(), std::to_string(anchor.Size()).c_str()));
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
					LOG_ERROR(StringUtils::format("nodeFactory::getComponents: Component '%s' has '%s' size keys!",
												  componentName.c_str(), std::to_string(size.Size()).c_str()));
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
				LOG_ERROR(StringUtils::format("nodeFactory::getComponents: Component '%s' no has sprite node type!", componentName.c_str()));
			}
		}
			break;
		case ANIMSPRITE_COMPONENT:
			break;
		case LABEL_COMPONENT: {
			if (auto label = dynamic_cast<Label*>(node)) {
				if (object.HasMember("fontType") && object["fontType"].IsString() && object["fontType"].GetString() == std::string("ttf")) {
					TTFConfig font;
					font.fontFilePath = "fonts/arial.ttf";
					font.fontSize = 12.f;

					TextHAlignment hAlignment = TextHAlignment::LEFT;
					float maxLineWidth = 0.f;
					if (object.HasMember("fontSize") && (object["fontSize"].IsFloat() || object["fontSize"].IsInt())) {
						font.fontSize = object["fontSize"].GetFloat();
					}
					if (object.HasMember("fontFile") && object["fontFile"].IsString()) {
						font.fontFilePath = object["fontFile"].GetString();
					}
					if (object.HasMember("bold") && object["bold"].IsBool()) {
						font.bold = object["bold"].GetBool();
					}
					if (object.HasMember("italics") && object["italics"].IsBool()) {
						font.italics = object["italics"].GetBool();
					}
					if (object.HasMember("alight") && object["alight"].IsString()) {
						auto alight = object["alight"].GetString();
						if (alight == std::string("center")) {
							hAlignment = TextHAlignment::CENTER;
						} else
						if (alight == std::string("left")) {
							hAlignment = TextHAlignment::LEFT;
						} else
						if (alight == std::string("right")) {
							hAlignment = TextHAlignment::RIGHT;
						}
					}
					if (object.HasMember("maxLineWidth") && (object["maxLineWidth"].IsFloat() || object["maxLineWidth"].IsInt())) {
						maxLineWidth = object["maxLineWidth"].GetFloat();
					}
					if (object.HasMember("text") && object["text"].IsString()) {
						label->initWithTTF(font, object["text"].GetString(), hAlignment, static_cast<int>(maxLineWidth));
					} else {
						label->setTTFConfig(font);
						label->setAlignment(hAlignment);
						label->setMaxLineWidth(maxLineWidth);
					}
				}
			} else {
				LOG_ERROR(StringUtils::format("nodeFactory::getComponents: Component '%s' no has label node type!", componentName.c_str()));
			}
		}
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
