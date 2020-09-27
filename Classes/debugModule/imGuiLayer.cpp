#include "imGuiLayer.h"

using namespace mercenaryBattles;
using namespace mercenaryBattles::debugModule;

void imGuiLayer::_onStart() {
	std::string layerName = "ImGUILayer";
	auto order = INT_MAX;
	auto layer = ImGuiLayer::create();
	this->addChild(layer, order, layerName);

	//Buttons
	CCIMGUI::getInstance()->addCallback([this](){
		static bool nodeEditorOpened = false;
		static bool engineInfoOpened = false;
		static bool devicesListOpened = false;

		if (ImGui::Button("Debug")) {
			nodeEditorOpened = !nodeEditorOpened;
		}
		if (ImGui::Button("Engine")) {
			engineInfoOpened = !engineInfoOpened;
		}
		if (ImGui::Button("Devices")) {
			devicesListOpened = !devicesListOpened;
		}

		if (nodeEditorOpened) showNodeEditor(&nodeEditorOpened);
//		if (engineInfoOpened) showEngineInfo(&engineInfoOpened);
//		if (devicesListOpened) showDevicesList(&devicesListOpened);

		/*if (nodeEditorOpened) {
			CCIMGUI::getInstance()->addCallback([=](){
				ImGui::Text("Hello, world!");
				// create button with Sprite, auto pushID / popID with texture id
//				CCIMGUI::getInstance()->imageButton(sp, ImVec2(0, 0));
			}, "hello");
		} else {
			CCIMGUI::getInstance()->removeCallback("hello");
		}*/
	}, "buttons");

//	_addArmature();

}

void imGuiLayer::showNodeEditor(bool *nodeEditorOpened) {
	ImGui::SetNextWindowSize(ImVec2(static_cast<float>(nodeEditorW), static_cast<float>(nodeEditorH)),
							 ImGuiCond_FirstUseEver);
	if (!ImGui::Begin("Property editor", reinterpret_cast<bool *>(nodeEditorOpened))) {
		ImGui::End();
		return;
	}

	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
	ImGui::Columns(2);
	ImGui::Separator();

	renderTree(cocos2d::Director::getInstance()->getRunningScene()->getChildren());
	ImGui::NextColumn();
	renderPreferences(lastTarget);

	ImGui::Columns(1);
	ImGui::Separator();
	ImGui::PopStyleVar();
	ImGui::End();
};

ImRect imGuiLayer::renderTree(cocos2d::Vector<Node *> n) {
	const ImRect nodeRect = ImRect(ImGui::GetItemRectMin(), ImGui::GetItemRectMax());
	if (lastTarget == nullptr) {
		lastTarget = n.front();
	}
	for (auto &node : n) {
		ImGui::AlignTextToFramePadding();
		std::string className = {};
//		auto test = typeid(*node).name(); // need only for debug
		if (classList.find(typeid(*node).name()) != classList.end()) {
			className = classList[typeid(*node).name()] + " ";
		}
		const std::string name = className + node->getName() + (node->isVisible() ? "" : " #inactive");
		ImGuiTreeNodeFlags nodeFlags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick |
									   ImGuiTreeNodeFlags_SpanAvailWidth;
		if (lastTarget == node) {
			nodeFlags |= ImGuiTreeNodeFlags_Selected;
		}
		if (node->getChildren().empty()) {
			nodeFlags |= ImGuiTreeNodeFlags_Leaf;
		}
		bool nodeOpen = ImGui::TreeNodeEx((void *) (intptr_t) node->_ID, nodeFlags, "%s", name.c_str());
		if (ImGui::IsItemClicked()) {
			//id of clicked element
			lastTarget = node;
		}
		if (nodeOpen) {
			ImGui::PushID(node);

			renderTree(node->getChildren());
			ImGui::PopID();
			ImGui::TreePop();
		}
	}


	return nodeRect;
}

ImRect imGuiLayer::renderPreferences(Node *node) {
	const ImRect prefRect = ImRect(ImGui::GetItemRectMin(), ImGui::GetItemRectMax());
	if (node == nullptr) {
		return prefRect;
	}

	ImGui::SetNextItemOpen(true, ImGuiCond_Once);
	if (ImGui::CollapsingHeader("General info")) {
		ImGui::Text("Node Name(ID) %s", node->getName().c_str());
		ImGui::Text("Node GUI %d", node->_ID);
		auto active = node->isVisible();
		auto tempActive = active;
		ImGui::Checkbox(" Is active", &active);
		if (active != tempActive && node->getName() != "ImGUILayer") {
			node->setVisible(active);
		}
	}

	ImGui::SetNextItemOpen(true, ImGuiCond_Once);
	if (ImGui::CollapsingHeader("Transform component")) {
		/**
		 * Height and Width
		 */
		auto width = node->getContentSize().width;
		auto height = node->getContentSize().height;
		float vecWH[2] = {width, height};
		ImGui::DragFloat2("Width/Height", vecWH, 1);
		if (vecWH[0] != width || vecWH[1] != height) {
			auto _size = cocos2d::Size();
			_size.width = vecWH[0];
			_size.height = vecWH[1];
			node->setContentSize(_size);
		}
		/**
		 * Position by X and Y
		 */
		auto nodePos = node->getPosition();
		float vecPos[2] = {nodePos.x, nodePos.y};
		ImGui::DragFloat2("Position X/Y", vecPos, 1.f);
		if (vecPos[0] != nodePos.x || vecPos[1] != nodePos.y) {
			node->setPosition(vecPos[0], vecPos[1]);
		}
		/**
		 * Anchor
		 */
		auto nodeAnchor = node->getAnchorPoint();
		float vecAnchor[2] = {nodeAnchor.x, nodeAnchor.y};
		ImGui::DragFloat2("Anchor X/Y", vecAnchor, 0.1f, -1.f, 1.f);
		if (vecAnchor[0] != nodeAnchor.x || vecAnchor[1] != nodeAnchor.y) {
			node->setAnchorPoint({vecAnchor[0], vecAnchor[1]});
		}
		/**
		 * Scale X and Y
		 */
		auto nodeScaleX = node->getScaleX();
		auto nodeScaleY = node->getScaleY();
		auto tempScaleX = nodeScaleX;
		auto tempScaleY = nodeScaleY;
		float vecScale[2] = {nodeScaleX, nodeScaleY};
		ImGui::DragFloat2("Scale X/Y", vecScale, 0.01f);
		if (tempScaleX != vecScale[0] || tempScaleY != vecScale[1]) {
			node->setScaleX(vecScale[0]);
			node->setScaleY(vecScale[1]);
		}
		/**
		 * Skew X and Y
		 */
		auto nodeSkewX = node->getSkewX();
		auto nodeSkewY = node->getSkewY();
		auto tempSkewX = nodeSkewX;
		auto tempSkewY = nodeSkewY;
		float vecSkew[2] = {nodeSkewX, nodeSkewY};
		ImGui::DragFloat2("Skew X/Y", vecSkew, 0.1f);
		if (tempSkewX != vecSkew[0] || tempSkewY != vecSkew[1]) {
			node->setSkewX(vecSkew[0]);
			node->setSkewY(vecSkew[1]);
		}
		/**
		 * Rotation
		 */
		auto nodeRotation = node->getRotation();
		auto tempRotation = nodeRotation;
		float floatRotation[1] = {nodeRotation};
		ImGui::DragFloat("Rotation", floatRotation, 0.1f);
		if(floatRotation[0] != tempRotation) {
			node->setRotation(floatRotation[0]);
		}
	}

	ImGui::SetNextItemOpen(true, ImGuiCond_Once);
	if (ImGui::CollapsingHeader("Sprite component")) {
//		std::string image = "Image: " + node->getComponent<SpriteComponent>().getImagePath();
//		ImGui::Text("%s", image.c_str());
	}

	return prefRect;
}
