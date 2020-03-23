/* Copyright 2020 psychobmx
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT(\
    k00, k10, k20, k30, k40, k50,      k70, k80, k90, k100, k110, k120,\
    k01, k11, k21, k31, k41, k51, k61, k71, k81, k91, k101, k111, k121,\
    k02, k12, k22, k32, k42, k52, k62, k72, k82, k92, k102, k112, k122,\
                   k33, k43, k53,      k73, k83, k93\
) { \
    {k00,   k10,   k20,   k30,   k40,   k50, KC_NO, k70,   k80,   k90, k100,   k110,   k120},\
    {k01,   k11,   k21,   k31,   k41,   k51, k61,   k71,   k81,   k91, k101,   k111,   k121},\
    {k02,   k12,   k22,   k32,   k42,   k52, k62,   k72,   k82,   k92, k102,   k112,   k122},\
    {KC_NO, KC_NO, KC_NO, k33,   k43,   k53, KC_NO, k73,   k83,   k93, KC_NO, KC_NO,  KC_NO}\
}

