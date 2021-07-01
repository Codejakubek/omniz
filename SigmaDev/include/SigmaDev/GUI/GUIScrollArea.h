////////////////////////////////////////
//
// SigmaDev - Game Development and Multimedia Library
// Copyright (C) 2020-2021 Dawid Jakubowski (jakubowski.dawid@gmail.com)
//
// SigmaDev Library is licensed under MIT License (You can find it in the LICENSE file)
// Most recent version of the library is found on github repository: 
// https://github.com/Codedemens/SigmaDev/
// 
// 
// File: /impl/include/SigmaDev/GUI/GUIScrollArea.h
// Description:
// Additional Notes:

#ifndef SD_GUI_GUISCROLLAREA_H
#define SD_GUI_GUISCROLLAREA_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <SigmaDev/Graphics/ExpandableSprite.h>
#include <SigmaDev/GUI/GUIObject.h>
#include <SigmaDev/Graphics/GraphicsDefines.h>
#include <SFML/Audio.hpp>

class SD_ExpandableSprite;
class SD_SDD_SliderInitialization;

////////////////////////////////////////
enum SD_GUIScrollAreaDirection {
    SD_GUI_SCROLL_AREA_DIRECTION_UNKNOWN = 0,
    SD_GUI_SCROLL_AREA_DIRECTION_VERTICAL,
    SD_GUI_SCROLL_AREA_DIRECTION_HORIZONTAL,
    SD_GUI_SCROLL_AREA_DIRECTION_BOTH_VERTICAL_AND_HORIZONTAL
};
////////////////////////////////////////


#endif