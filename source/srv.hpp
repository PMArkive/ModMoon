/*
*   This file is part of ModMoon
*   Copyright (C) 2018-2019 Swiftloke
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

//Thanks to Sono for this code to subscribe to SRV events!

#ifndef LZZ_srv_h
#define LZZ_srv_h
#include <3ds.h>

typedef void (* SignalHandler) (u32);
struct SignalHook
{
  u32 notificaton;
  SignalHandler func;
  SignalHook * next;
};
class srv
{
public:
  static Handle notifsemaphore;
  static RecursiveLock rlock;
  static int count;
  static SignalHook sigroot;
  static vu8 running;
  static Thread thread;
  static Result init ();
  static void exit ();
  static void lock ();
  static void unlock ();
  static void handlerloop (void * param);
  static void hook (u32 notifid, SignalHandler func);
};
#endif
