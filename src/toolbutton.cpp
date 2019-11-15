/*
    src/toolbutton.cpp -- [Normal/Toggle/Radio/Popup] Button widget

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    Toolbutoon.cpp file was developed by Dalerank <dalerankn8@gmail.com>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/toolbutton.h>
#include <nanovg.h>
#include <nanogui/common.h>
#include <nanogui/serializer/json.h>
#include <nanogui/serializer/core.h>

NAMESPACE_BEGIN(nanogui)

void ToggleButton::beforeDoCallback()
{
  const Color& acolor = mActiveColor.w() ? mActiveColor : theme()->mToggleButtonActiveColor;
  const Color& icolor = mInactiveColor.w() ? mInactiveColor : theme()->mToggleButtonInactiveColor;
  mTextColor = mPushed ? icolor : acolor;
}

void ToggleButton::draw(NVGcontext* ctx)
{
  Button::draw(ctx);
  if (mFocused)
  {
    nvgStrokeWidth(ctx, 1.0f);
    nvgBeginPath(ctx);
    nvgRect(ctx, mPos.x() - 0.5f, mPos.y() - 0.5f, mSize.x() + 1, mSize.y() + 1);
    nvgStrokeColor(ctx, nvgRGBA(255, 0, 0, 255));
    nvgStroke(ctx);
  }
}

NAMESPACE_END(nanogui)
