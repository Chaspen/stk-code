//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2013 Glenn De Jonghe
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef HEADER_ACHIEVEMENTS_SLOT_HPP
#define HEADER_ACHIEVEMENTS_SLOT_HPP

#include "utils/types.hpp"
#include "achievements/achievement.hpp"

#include <irrString.h>
#include <string>
#include "io/xml_node.hpp"


class AchievementsSlot
{
private:
    std::map<uint32_t, Achievement *> m_achievements;
    bool m_online;
    bool m_valid;
    std::string m_id;

    void createFreshSlot();

public :
    AchievementsSlot(const XMLNode * input);
    AchievementsSlot(std::string id, bool online);
    bool isValid() const { return m_valid;}
    void save(std::ofstream & out);
    bool isOnline() const {return m_online;}
    void sync();
    void onRaceEnd();
    const std::string & getID() const {return m_id;}
    Achievement * getAchievement(uint32_t id);
};

#endif

/*EOF*/
