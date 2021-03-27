#include "customNodeTypes.h"
#include "common/coreModule/nodes/nodeFactory.h"
//interface module
#include "interfaceModule/widgets/cardProgressBar.h"
//battle module
#include "battleModule/interface/iconLabel.h"

//all windows
#include "interfaceModule/windows/notifyWindow.h"

using namespace mb::interfaceModule;

void customNodeTypes::registerAllCustomNodes() {
    //interface module
    GET_NODE_FACTORY().registerCustomNodeType("cardProgressBar", []() { return new cardProgressBar(); });
    //battle module
    GET_NODE_FACTORY().registerCustomNodeType("iconLabelBattle", []() { return new battleModule::iconLabel(); });

    // register all windows
    GET_GAME_MANAGER().registerWindow("notifyWindow", [](){ return new notifyWindow(); });
}
