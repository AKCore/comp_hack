/**
 * @file libcomp/src/Object.cpp
 * @ingroup libcomp
 *
 * @author COMP Omega <compomega@tutanota.com>
 *
 * @brief Base class for an object generated by the object generator (objgen).
 *
 * This file is part of the COMP_hack Library (libcomp).
 *
 * Copyright (C) 2012-2016 COMP_hack Team <compomega@tutanota.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Object.h"

using namespace libcomp;

Object::Object()
{
}

Object::~Object()
{
}

std::unordered_map<std::string, const tinyxml2::XMLElement*>
    Object::GetXmlMembers(const tinyxml2::XMLElement& root) const
{
    std::unordered_map<std::string, const tinyxml2::XMLElement*> members;

    const tinyxml2::XMLElement *pMember = root.FirstChildElement("member");

    while(nullptr != pMember)
    {
        const char *szName = pMember->Attribute("name");

        if(nullptr != szName)
        {
            members[szName] = pMember;
        }

        pMember = pMember->NextSiblingElement("member");
    }

    return members;
}

std::string Object::GetXmlText(const tinyxml2::XMLElement& root) const
{
    std::string value;

    const tinyxml2::XMLNode *pChild = root.FirstChild();

    if(nullptr != pChild)
    {
        const tinyxml2::XMLText *pText = pChild->ToText();

        if(nullptr != pText)
        {
            const char *szText = pText->Value();

            if(nullptr != szText)
            {
                value = szText;
            }
        }
    }

    return value;
}