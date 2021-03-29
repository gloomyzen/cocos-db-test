#ifdef DEBUG
#ifndef MERCENARY_BATTLES_HEROPROFILEDEBUG_H
#define MERCENARY_BATTLES_HEROPROFILEDEBUG_H

namespace mb::debugProfile {

    class heroProfileDebug {
      public:
        heroProfileDebug();
        ~heroProfileDebug();
        static heroProfileDebug& getInstance();

        void update();

      private:
        bool isOpened = false;
    };
}

#endif// MERCENARY_BATTLES_HEROPROFILEDEBUG_H
#endif
