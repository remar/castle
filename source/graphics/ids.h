#ifndef IDENTIFIERS_H
#define IDENTIFIERS_H

// Animation enums
enum {STAND_RIGHT, WALK_RIGHT, JUMP_RIGHT, STAND_LEFT, WALK_LEFT, JUMP_LEFT};
enum {OK_MARKER, RED_MARKER};
enum {CLOSED_GOAL, OPEN_GOAL};
enum {GREEN_BLIP, YELLOW_BLIP, RED_BLIP};
enum {PLACE_BRICK, BLINK_BRICK};
enum {SWEEPER_RIGHT, SWEEPER_LEFT};
enum {TRUNDLER_RIGHT, TRUNDLER_LEFT, TRUNDLER_PAUSE};
enum {BLOCK_ON, BLOCK_OFF};
enum {SWITCH_LIT, SWITCH_OFF};

// Sprite definitions
enum {PLAYER = 0, MARKER, BREAKABLE, PICKUP_01, PICKUP_02, PICKUP_03, PICKUP_04,
      PICKUP_05, PICKUP_06, PICKUP_07, PICKUP_08, PICKUP_09, PICKUP_10,
      PICKUP_11, PICKUP_12, PICKUP_13, PICKUP_14, COIN, GOAL, BLIP,
      BLUE_SPARK, RED_SPARK, BOOTS, SWEEPER, TRUNDLER, TRAPPER,
      BLOCK_YELLOW, BLOCK_GREEN, BLOCK_BLUE,
      SWITCH_YELLOW, SWITCH_GREEN, SWITCH_BLUE,
      TELE_YELLOW, TELE_GREEN, TELE_BLUE,
      TARGET_YELLOW, TARGET_GREEN, TARGET_BLUE,
      LAST_SPRITE};

// Tile set definitions
enum {SMALL_TILES = 0, LARGE_TILES, BG_MAIN, BORDER, LAST_TILESET};

#endif