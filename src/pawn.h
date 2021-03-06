/*
    Copyright (C) 2009 Andrew Caudwell (acaudwell@gmail.com)

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version
    3 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PAWN_H
#define PAWN_H

#include <string>

#include "gource_settings.h"

#include "core/display.h"
#include "core/fxfont.h"
#include "core/vectors.h"
#include "core/quadtree.h"

class Pawn : public QuadItem {
protected:
    vec2f pos;
    vec2f shadowOffset;

    vec3f screenpos;

    std::string name;
    float namewidth;
    float size;
    vec2f accel;
    float speed;

    float elapsed;
    float fadetime;

    float nametime;
    float name_interval;
    vec3f namecol;
    vec3f selectedcol;

    bool shadow;

    bool hidden;

    int tagid;

    FXFont font;

    float graphic_ratio;
    TextureResource* graphic;

    bool mouseover;

    virtual bool nameVisible() const;

    virtual void drawNameText(float alpha) const;
    virtual const vec3f& getNameColour() const;
protected:
    bool selected;
public:
    Pawn(const std::string& name, vec2f pos, int tagid);
    const vec2f & getPos() const { return pos; }
    void setPos(vec2f pos);

    void calcScreenPos(const vec2f& offset);

    void updateQuadItemBounds();

    void showName();

    void setMouseOver(bool over);

    float getSize();
    int getTagID();
    std::string getName();

    virtual void setSelected(bool selected);
    bool isSelected() { return selected; };

    void setHidden(bool hidden){ this->hidden = hidden; }
    bool isHidden() const { return hidden; }

    virtual float getAlpha() const{ return std::min(elapsed/fadetime, 1.0f); }
    virtual vec3f getColour() const { return vec3f(1.0, 1.0, 1.0); }

    void setGraphic(TextureResource* graphic);

    void logic(float dt);
    void draw(float dt);
    void drawShadow(float dt);
    void drawSimple(float dt);

    void drawName() const;
};

extern float gGourceShadowStrength;

#endif

