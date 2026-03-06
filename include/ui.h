#pragma once

enum AutonMode {
    AUTON_NONE,
    AUTON_SKILLS,
    AUTON_PUSH7RIGHT,
    AUTON_M3L4LEFT,
    AUTON_AWPLEFT
};

extern AutonMode selectedAuton;

void uiInit();
void uiUpdate();
