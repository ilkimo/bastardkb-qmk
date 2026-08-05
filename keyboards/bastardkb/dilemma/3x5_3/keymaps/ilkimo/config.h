/* Copyright 2024 il_kimo
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

/* Tap-hold tuning. Achordion handles the disambiguation, so PERMISSIVE_HOLD
 * stays off -- enabling both fights over the same decisions. */
#define TAPPING_TERM 185
#define TAPPING_TERM_PER_KEY
// #define PERMISSIVE_HOLD // good with Achordion
#define ACHORDION_STREAK

/* Leader key. */
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 300

/* Combos. */
#define COMBO_TERM 40
