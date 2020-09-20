#ifndef COCOS_DB_IMGUILAYER_H
#define COCOS_DB_IMGUILAYER_H

#include <imgui.h>
#include <CCIMGUI.h>
#include "cocos2d.h"
#include "CCImGuiLayer.h"

namespace mercenaryBattles {
	namespace debugModule {
		class imGuiLayer : public cocos2d::LayerColor {
		protected:
			cocos2d::Sprite *_background;

			virtual void _onStart() {
				std::string layerName = "ImGUILayer";
				auto order = INT_MAX;
				auto layer = ImGuiLayer::create();
				this->addChild(layer, order, layerName);

				// enable docking
				auto& io = ImGui::GetIO();
				io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
				auto sp = cocos2d::Sprite::create("HelloWorld.png");
				layer->addChild(sp);
				// add ui callbacks
				CCIMGUI::getInstance()->addCallback([=](){
					ImGui::Text("Hello, world!");
					// create button with Sprite, auto pushID / popID with texture id
					CCIMGUI::getInstance()->imageButton(sp, ImVec2(0, 0));
				}, "hello");
				// remove ui callbacks to stop rendering
				CCIMGUI::getInstance()->removeCallback("hello");
				// add chinese font
//				io.Fonts->AddFontFromFileTTF("path/to/font.ttf", 16.0f, 0, io.Fonts->GetGlyphRangesChineseFull());
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

			virtual bool init() {
				if (!LayerColor::initWithColor(cocos2d::Color4B(105, 105, 105, 255))) {
					return false;
				}

//				const auto &stageSize = cocos2d::Director::getInstance()->getVisibleSize();
//				setPosition(stageSize.width * 0.5f, stageSize.height * 0.5f);
//
//				_background = cocos2d::Sprite::create("background.png");
//				addChild(_background);

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
		};
	}
}

#endif //COCOS_DB_IMGUILAYER_H
