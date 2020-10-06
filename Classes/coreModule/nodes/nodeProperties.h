#ifndef MERCENARY_BATTLES_NODEPROPERTIES_H
#define MERCENARY_BATTLES_NODEPROPERTIES_H

#include "debugModule/logManager.h"
#include "cocos2d.h"
#include <string>
#include "rapidjson/document.h"

namespace mb {
	using namespace cocos2d;

	namespace coreModule {

		class nodeProperties : public Node {
		public:
			Node* findNode(const std::string &name, Node *node);
			/***
		 	 * Парсинг параметров из json файла
		 	 * @param path relative path to file
			 * @param node Node instance
		 	 */
			void loadProperty(const std::string &path, Node *node);
			void parseComponents(Node *node, const std::string &string, bool recursive = false);
			void enableDebug(bool value);
			bool debugDrawEnabled() const { return isDebugEnabled; }
			virtual void draw(Renderer* renderer, const Mat4& transform, uint32_t flags);

		private:
			void addDebugDraw();
			void removeDebugDraw();
			bool isDebugEnabled = false;
			DrawNode* debugNode = nullptr;
			void parseData(Node *node, const rapidjson::GenericValue<rapidjson::UTF8<char>>::Array &array);
		};
	}
}//mb::coreModule

#endif //MERCENARY_BATTLES_NODEPROPERTIES_H
