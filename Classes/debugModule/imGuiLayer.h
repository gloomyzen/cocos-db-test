#ifndef COCOS_DB_IMGUILAYER_H
#define COCOS_DB_IMGUILAYER_H

#include <imgui.h>
#include <imgui_internal.h>
#include <CCIMGUI.h>
#include <vector>
#include <list>
#include "cocos2d.h"
#include "CCImGuiLayer.h"
#include "dragonBones/cocos2dx/CCDragonBonesHeaders.h"

namespace mercenaryBattles {
	namespace debugModule {
		class imGuiLayer : public cocos2d::Layer {
		protected:
			cocos2d::Sprite *_background;

			void _onStart();

			void update(float dt) override {
				if (!this->isVisible()) {
					this->setVisible(true);
				}
			}

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

			bool init() override {
				if (!Layer::init()) {
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
				classList[typeid(cocos2d::Label).name()] = "Label";
				// Layers
				classList[typeid(cocos2d::Layer).name()] = "Layer";
				classList[typeid(cocos2d::LayerColor).name()] = "LayerColor";
				classList[typeid(imGuiLayer).name()] = "imGuiLayer";
				//Actions
				classList[typeid(cocos2d::Action).name()] = "Action";
				//TODO add DragonBones node
				classList[typeid(dragonBones::CCArmatureDisplay).name()] = "DBRoot";
				classList[typeid(dragonBones::DragonBones).name()] = "DBPart";
				classList[typeid(dragonBones::Armature).name()] = "DBArmature";

				_onStart();
				scheduleUpdate();

				return true;
			}


			float getStageWidth() const {
				const auto &stageSize = cocos2d::Director::getInstance()->getVisibleSize();
				return stageSize.width;
			}

			float getStageHeight() const {
				const auto &stageSize = cocos2d::Director::getInstance()->getVisibleSize();
				return stageSize.height;
			}

//			void _addArmature()
//			{
//				if (_armatures.empty())
//				{
//					dragonBones::CCFactory::getFactory()->loadDragonBonesData("mecha_1406/mecha_1406_ske.dbbin");
//					dragonBones::CCFactory::getFactory()->loadTextureAtlasData("mecha_1406/mecha_1406_tex.json");
//				}
//
//				const auto armatureDisplay = dragonBones::CCFactory::getFactory()->buildArmatureDisplay("mecha_1406");
//				armatureDisplay->setScale(0.3f);
//				armatureDisplay->setPosition(333.f, 26.f);
//				armatureDisplay->getArmature()->setCacheFrameRate(24);
//				armatureDisplay->getAnimation()->play("walk");
//				addChild(armatureDisplay);
//
//				_armatures.push_back(armatureDisplay);
//			}

		private:
			std::vector<dragonBones::CCArmatureDisplay*> _armatures;
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
