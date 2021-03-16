#include "customNodeTypes.h"
#include "common/coreModule/nodes/nodeFactory.h"
#include "interfaceModule/widgets/cardProgressBar.h"

//all windows
#include "interfaceModule/windows/notifyWindow.h"

using namespace mb::interfaceModule;

void customNodeTypes::registerAllCustomNodes() {
    GET_NODE_FACTORY().registerCustomNodeType("cardProgressBar", []() { return new cardProgressBar(); });

    // register all windows
    GET_GAME_MANAGER().registerWindow("notifyWindow", [](){ return new notifyWindow(); });
}
