#ifndef MERCENARY_BATTLES_PLAYERDATA_H
#define MERCENARY_BATTLES_PLAYERDATA_H

#include "cocos2d.h"
#include "common/coreModule/nodes/nodeProperties.h"
#include "common/coreModule/nodes/widgets/node3d.h"
#include "battleModule/battleObject.h"
#include "battleModule/battleField.h"
#include <string>

namespace mb::battleModule {
    class playerData {
      public:
        enum class ePlayerPosition { LEFT = 0, RIGHT };
        enum class ePlayerMode { PVE = 0, PVP };
        enum class ePlayerFraction { HUMAN = 0, ORC };
        playerData();
        ~playerData();

        void setPlayerPosition(ePlayerPosition value) { playerPosition = value; }
        ePlayerPosition getPLayerPosition() { return playerPosition; }
        void setPlayerMode(ePlayerMode value) { playerMode = value; }
        ePlayerMode getPlayerMode() { return playerMode; }
        void setPlayerFraction(ePlayerFraction value) { playerFraction = value; }
        ePlayerFraction getPlayerFraction() { return playerFraction; }
        void setRealUser(bool value) { isRealUser = value; }
        bool getRealUser() const { return isRealUser; }
        void setBattleField(battleField* value) { bf = value; }

        void init();

      private:
        void initCastle();

        ePlayerPosition playerPosition = ePlayerPosition::LEFT;
        ePlayerMode playerMode = ePlayerMode::PVE;
        ePlayerFraction playerFraction = ePlayerFraction::HUMAN;
        bool isRealUser = false;
        battleField* bf = nullptr; //is not owner
        battleObject* castle = nullptr;
        bool inited = false;
    };
}// namespace mb::battleModule


#endif// MERCENARY_BATTLES_PLAYERDATA_H
