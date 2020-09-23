#include "imGuiLayer.h"

using namespace mercenaryBattles;
using namespace mercenaryBattles::debugModule;

void imGuiLayer::_onStart() {
	std::string layerName = "ImGUILayer";
	auto order = INT_MAX;
	auto layer = ImGuiLayer::create();
	this->addChild(layer, order, layerName);

	// enable docking
	ImGuiIO &io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

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


	/*CCIMGUI::getInstance()->addCallback([this](){
		if (ImGui::Button("Debug")) {
//			nodeEditorOpened = !nodeEditorOpened;
		}
		if (ImGui::Button("Engine")) {
//			engineInfoOpened = !engineInfoOpened;
		}
		if (ImGui::Button("Devices")) {
//			devicesListOpened = !devicesListOpened;
		}
	}, "hello");*/
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

	auto test = cocos2d::Director::getInstance()->getRunningScene()->getChildren();
	renderTree(cocos2d::Director::getInstance()->getRunningScene()->getChildren());
//	ImGui::NextColumn();
//	renderPreferences(GET_NODE()->findNode(lastTarget));

	ImGui::Columns(1);
	ImGui::Separator();
	ImGui::PopStyleVar();
	ImGui::End();
};

ImRect imGuiLayer::renderTree(cocos2d::Vector<Node *> n) {
	const ImRect nodeRect = ImRect(ImGui::GetItemRectMin(), ImGui::GetItemRectMax());
	if (lastTarget == 0u) {
		lastTarget = n.front()->_ID;
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
		if (lastTarget == node->_ID) {
			nodeFlags |= ImGuiTreeNodeFlags_Selected;
		}
		if (node->getChildren().empty()) {
			nodeFlags |= ImGuiTreeNodeFlags_Leaf;
		}
		bool nodeOpen = ImGui::TreeNodeEx((void *) (intptr_t) node->_ID, nodeFlags, "%s", name.c_str());
		if (ImGui::IsItemClicked()) {
			//id of clicked element
			lastTarget = node->_ID;
		}
		if (nodeOpen) {
			ImGui::PushID(node->_ID);

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
//		ImGui::Text("Node Name(ID) %s", node->getId().c_str());
//		ImGui::Text("Node GUI %u", node->getUid());
//		auto &active = node->getActive();
//		ImGui::Checkbox(" Is active", &active);
	}

	ImGui::SetNextItemOpen(true, ImGuiCond_Once);
	if (ImGui::CollapsingHeader("Transform component")) {
//		auto width = node->getComponent<TransformComponent>().getWidth();
//		auto height = node->getComponent<TransformComponent>().getHeight();
//		int vecWH[2] = {width, height};
//		ImGui::DragInt2("Width/Height", vecWH, 1);
//		if (vecWH[0] != width) {
//			node->getComponent<TransformComponent>().setWidth(vecWH[0]);
//		}
//		if (vecWH[1] != height) {
//			node->getComponent<TransformComponent>().setHeight(vecWH[1]);
//		}
//		auto position = node->getComponent<TransformComponent>().getPosition();
//		auto xPos = position.getX();
//		auto yPos = position.getY();
//		float vecPos[2] = {xPos, yPos};
//		ImGui::DragFloat2("X/Y position", vecPos, 1.f);
//		if (vecPos[0] != xPos) {
//			node->getComponent<TransformComponent>().setX(vecPos[0]);
//		}
//		if (vecPos[1] != yPos) {
//			node->getComponent<TransformComponent>().setY(vecPos[1]);
//		}
//		auto scale = node->getComponent<TransformComponent>().getScale();
//		auto tempScale = scale;
//		ImGui::DragFloat("Scale", &scale, 0.1f);
//		if (tempScale != scale) {
//			node->getComponent<TransformComponent>().setScale(scale);
//		}
	}

	ImGui::SetNextItemOpen(true, ImGuiCond_Once);
	if (ImGui::CollapsingHeader("Sprite component")) {
//		std::string image = "Image: " + node->getComponent<SpriteComponent>().getImagePath();
//		ImGui::Text("%s", image.c_str());
	}

	return prefRect;
}
