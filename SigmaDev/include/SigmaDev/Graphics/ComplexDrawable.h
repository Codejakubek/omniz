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
// File: /impl/include/SigmaDev/Graphics/ComplexDrawable.h
// Description:
// Additional Notes:

#ifndef SD_GRAPHICS_COMPLEX_DRAWABLE_H
#define SD_GRAPHICS_COMPLEX_DRAWABLE_H

#include <SigmaDev/Windows/WindowsDefines.h>
#include <SigmaDev/Misc/Class.h>

////////////////////////////////////////

class SD_ComplexDrawable : public SD_Class {
public:
    SD_DECLARE_CLASS_H()

    SD_ComplexDrawable();
    virtual ~SD_ComplexDrawable();

    virtual void Render(SD_RenderWindowAccess render_window_access) const;

protected:

};
////////////////////////////////////////

#endif
