#ifndef COCOS_DB_IMGUILAYER_H
#define COCOS_DB_IMGUILAYER_H

#include <imgui.h>
#include <imgui_internal.h>
#include <CCIMGUI.h>
#include <vector>
#include <list>
#include "cocos2d.h"
#include "CCImGuiLayer.h"

namespace mercenaryBattles {
	namespace debugModule {
		class imGuiLayer : public cocos2d::LayerColor {
		protected:
			cocos2d::Sprite *_background;

			void _onStart();

		public:
			CREATE_FUNC(imGuiLayer);

			static cocos2d::Scene* createScene()
			{
				auto scene = cocos2d::Scene::create();
				auto layer = imGuiLayer::create();

				scene->addChild(layer);
				return scene;
			}
			imGuiLayer() : _background(nullptr) {}

			virtual bool init() {
				if (!LayerColor::initWithColor(cocos2d::Color4B(105, 105, 105, 255))) {
					return false;
				}

				//General
				classList[typeid(cocos2d::Camera).name()] = "Camera";
				classList[typeid(cocos2d::Scene).name()] = "Scene";
				// Nodes
				classList[typeid(cocos2d::Node).name()] = "Node";
				classList[typeid(cocos2d::ClippingNode).name()] = "ClippingNode";
				classList[typeid(cocos2d::DrawNode).name()] = "DrawNode";
				classList[typeid(cocos2d::ParticleBatchNode).name()] = "ParticleBatchNode";
				classList[typeid(cocos2d::SpriteBatchNode).name()] = "SpriteBatchNode";
				classList[typeid(cocos2d::ParallaxNode).name()] = "ParallaxNode";
				classList[typeid(cocos2d::RenderTexture).name()] = "RenderTexture";
				classList[typeid(cocos2d::ClippingRectangleNode).name()] = "ClippingRectangleNode";
				classList[typeid(cocos2d::AttachNode).name()] = "AttachNode";
				classList[typeid(cocos2d::Sprite).name()] = "Sprite";
				classList[typeid(cocos2d::NodeGrid).name()] = "NodeGrid";
				// Layers
				classList[typeid(cocos2d::Layer).name()] = "Layer";
				classList[typeid(cocos2d::LayerColor).name()] = "LayerColor";
				classList[typeid(imGuiLayer).name()] = "imGuiLayer";
				//Actions
				classList[typeid(cocos2d::Action).name()] = "Action";
				//TODO add DragonBones node

				const auto &stageSize = cocos2d::Director::getInstance()->getVisibleSize();
				setPosition(stageSize.width * 0.5f, stageSize.height * 0.5f);
//
				_background = cocos2d::Sprite::create("background.png");
				addChild(_background);

				_onStart();

				return true;
			}

			cocos2d::Label *createText(const std::string &string) {
				const auto text = cocos2d::Label::create();
				text->setPosition(0.0f, -(getStageHeight() * 0.5f - 100.f));
				text->setString(string);
				text->setAlignment(cocos2d::TextHAlignment::CENTER);
				addChild(text);

				return text;
			}

			float getStageWidth() const {
				const auto &stageSize = cocos2d::Director::getInstance()->getVisibleSize();
				return stageSize.width;
			}

			float getStageHeight() const {
				const auto &stageSize = cocos2d::Director::getInstance()->getVisibleSize();
				return stageSize.height;
			}

		private:
			/// Node editor
			std::map<std::string, std::string> classList;
			void showNodeEditor(bool *p_open);
			ImRect renderTree(cocos2d::Vector<Node*> n);
			ImRect renderPreferences(Node *);

			/***
		 	 * Debug button properties
		 	 */
			int debugBtnW = 65;
			int debugBtnH = 80;

			/***
			 * Node editor window
			 */
			int nodeEditorW = 430;
			int nodeEditorH = 450;
			Node* lastTarget = nullptr;
		};
	}
}

#endif //COCOS_DB_IMGUILAYER_H
