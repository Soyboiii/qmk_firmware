Soyboiii's split planck layout with unicode nordics, and alt codes via macro

Compile via QMK msys with: 
qmk compile -kb planck/rev6 -km soysplit

old mouse settings:
#define MOUSEKEY_DELAY 0 // delap before hold starts
#define MOUSEKEY_INTERVAL 16 // ms per next step
#define MOUSEKEY_MOVE_DELTA 2
#define MOUSEKEY_MAX_SPEED 2 // px per update?
#define MOUSEKEY_TIME_TO_MAX 0 // probably tenths of seconds

#define MOUSEKEY_WHEEL_DELAY 0 // delap before hold starts
#define MOUSEKEY_WHEEL_INTERVAL 25 // ms per next step
#define MOUSEKEY_WHEEL_MAX_SPEED 1 // rows per update?
#define MOUSEKEY_WHEEL_TIME_TO_MAX 0 // probably tenths of seconds