#include "DataManager.h"

#include <stdio.h>

#include <rage.h>
extern Rage rage;

#include "debug.h"

// Level data
#include "level_1_01_bin.h"
#include "level_1_02_bin.h"
#include "level_1_03_bin.h"
#include "level_1_04_bin.h"
#include "level_1_05_bin.h"
#include "level_1_06_bin.h"
#include "level_1_07_bin.h"
#include "level_1_08_bin.h"
#include "level_1_09_bin.h"
#include "level_1_10_bin.h"
#include "level_1_11_bin.h"
#include "level_1_12_bin.h"

// Graphics
#include "graphics/ids.h"

DataManager::DataManager()
  : set(0), level(0)
{
  initLevelData();
  clearLoadedInfo();
}

DataManager::~DataManager()
{

}

bool
DataManager::loadSprite(Screen screen, int id)
{
  if(spriteLoaded[screen == MAIN ? 0 : 1][id])
    return true;
  
#include "large_pickup01.h"
#include "small_pickup01.h"
#include "large_pickup02.h"
#include "small_pickup02.h"
#include "large_pickup03.h"
#include "small_pickup03.h"
#include "large_pickup04.h"
#include "small_pickup04.h"
#include "large_pickup05.h"
#include "small_pickup05.h"
#include "large_pickup06.h"
#include "small_pickup06.h"
#include "large_pickup07.h"
#include "small_pickup07.h"
#include "large_pickup08.h"
#include "small_pickup08.h"
#include "large_pickup09.h"
#include "small_pickup09.h"
#include "large_pickup10.h"
#include "small_pickup10.h"
#include "large_pickup11.h"
#include "small_pickup11.h"
#include "large_pickup12.h"
#include "small_pickup12.h"
#include "large_pickup13.h"
#include "small_pickup13.h"
#include "large_pickup14.h"
#include "small_pickup14.h"
#include "large_marker.h"
#include "small_marker.h"
#include "large_redmarker.h"
#include "small_redmarker.h"
#include "large_breakable.h"
#include "small_breakable.h"
#include "large_coin.h"
#include "small_coin.h"
#include "large_open_goal.h"
#include "large_closed_goal.h"
#include "small_open_goal.h"
#include "small_closed_goal.h"
#include "large_bluespark.h"
#include "small_bluespark.h"
#include "large_redspark.h"
#include "small_redspark.h"
#include "large_boots.h"
#include "small_boots.h"
#include "large_sweeper.h"
#include "small_sweeper.h"
#include "large_trundler.h"
#include "small_trundler.h"
#include "large_trapper.h"
#include "small_trapper.h"

#include "large_blockb.h"
#include "large_blockb_hole.h"
#include "small_blockb.h"
#include "small_blockb_hole.h"

#include "large_blockg.h"
#include "large_blockg_hole.h"
#include "small_blockg.h"
#include "small_blockg_hole.h"

#include "large_blocky.h"
#include "large_blocky_hole.h"
#include "small_blocky.h"
#include "small_blocky_hole.h"

#include "large_switchb.h"
#include "large_switchb_off.h"
#include "small_switchb.h"
#include "small_switchb_off.h"

#include "large_switchg.h"
#include "large_switchg_off.h"
#include "small_switchg.h"
#include "small_switchg_off.h"

#include "large_switchy.h"
#include "large_switchy_off.h"
#include "small_switchy.h"
#include "small_switchy_off.h"

#include "large_teleb.h"
#include "small_teleb.h"
#include "large_teleg.h"
#include "small_teleg.h"
#include "large_teley.h"
#include "small_teley.h"

#include "large_teleb_target.h"
#include "small_teleb_target.h"
#include "large_teleg_target.h"
#include "small_teleg_target.h"
#include "large_teley_target.h"
#include "small_teley_target.h"


  int retval = 0;

  #include "graphics/pickup.h"

  if(screen == MAIN) // Small sprites
    {
      if(id == PLAYER)
	{
	  Rage::ImageDefinition player_right;
	  Rage::ImageDefinition player_left;

#include "spr_right_guy1_small.h"
#include "spr_left_guy1_small.h"

	  player_right.gfx = spr_right_guy1_smallTiles;
	  player_right.gfxLen = spr_right_guy1_smallTilesLen;
	  player_right.pal = spr_right_guy1_smallPal;
	  player_right.palLen = spr_right_guy1_smallPalLen;

	  player_left.gfx = spr_left_guy1_smallTiles;
	  player_left.gfxLen = spr_left_guy1_smallTilesLen;
	  player_left.pal = spr_left_guy1_smallPal;
	  player_left.palLen = spr_left_guy1_smallPalLen;

	  {
#include "graphics/playerdef.h"
	    TRY(retval = rage.loadSprite(Rage::MAIN, &playerDef));
	  }
	}
      else if(id == MARKER)
	{
#include "graphics/small_marker.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallMarkerDef));
	}
      else if(id == BREAKABLE)
	{
#include "graphics/small_breakable.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallBreakableDef));
	}
      else if(id == PICKUP_01)
	{
	  pickupAnimation.image.gfx = small_pickup01Tiles;
	  pickupAnimation.image.gfxLen = small_pickup01TilesLen;
	  pickupAnimation.image.pal = small_pickup01Pal;
	  pickupAnimation.image.palLen = small_pickup01PalLen;
	  pickupAnimation.size = SpriteSize_16x16;
	  pickupDef.spriteID = PICKUP_01;
  
	  TRY(retval = rage.loadSprite(Rage::MAIN, &pickupDef));
	}
      else if(id == PICKUP_02)
	{
	  pickupAnimation.image.gfx = small_pickup02Tiles;
	  pickupAnimation.image.gfxLen = small_pickup02TilesLen;
	  pickupAnimation.image.pal = small_pickup02Pal;
	  pickupAnimation.image.palLen = small_pickup02PalLen;
	  pickupAnimation.size = SpriteSize_16x16;
	  pickupDef.spriteID = PICKUP_02;
  
	  TRY(retval = rage.loadSprite(Rage::MAIN, &pickupDef));
	}
      else if(id == PICKUP_03)
	{
	  pickupAnimation.image.gfx = small_pickup03Tiles;
	  pickupAnimation.image.gfxLen = small_pickup03TilesLen;
	  pickupAnimation.image.pal = small_pickup03Pal;
	  pickupAnimation.image.palLen = small_pickup03PalLen;
	  pickupAnimation.size = SpriteSize_16x16;
	  pickupDef.spriteID = PICKUP_03;
  
	  TRY(retval = rage.loadSprite(Rage::MAIN, &pickupDef));
	}
      else if(id == PICKUP_04)
	{
	  pickupAnimation.image.gfx = small_pickup04Tiles;
	  pickupAnimation.image.gfxLen = small_pickup04TilesLen;
	  pickupAnimation.image.pal = small_pickup04Pal;
	  pickupAnimation.image.palLen = small_pickup04PalLen;
	  pickupAnimation.size = SpriteSize_16x16;
	  pickupDef.spriteID = PICKUP_04;
  
	  TRY(retval = rage.loadSprite(Rage::MAIN, &pickupDef));
	}
      else if(id == PICKUP_05)
	{
	  pickupAnimation.image.gfx = small_pickup05Tiles;
	  pickupAnimation.image.gfxLen = small_pickup05TilesLen;
	  pickupAnimation.image.pal = small_pickup05Pal;
	  pickupAnimation.image.palLen = small_pickup05PalLen;
	  pickupAnimation.size = SpriteSize_16x16;
	  pickupDef.spriteID = PICKUP_05;
  
	  TRY(retval = rage.loadSprite(Rage::MAIN, &pickupDef));
	}
      else if(id == PICKUP_06)
	{
	  pickupAnimation.image.gfx = small_pickup06Tiles;
	  pickupAnimation.image.gfxLen = small_pickup06TilesLen;
	  pickupAnimation.image.pal = small_pickup06Pal;
	  pickupAnimation.image.palLen = small_pickup06PalLen;
	  pickupAnimation.size = SpriteSize_16x16;
	  pickupDef.spriteID = PICKUP_06;
  
	  TRY(retval = rage.loadSprite(Rage::MAIN, &pickupDef));
	}
      else if(id == PICKUP_07)
	{
	  pickupAnimation.image.gfx = small_pickup07Tiles;
	  pickupAnimation.image.gfxLen = small_pickup07TilesLen;
	  pickupAnimation.image.pal = small_pickup07Pal;
	  pickupAnimation.image.palLen = small_pickup07PalLen;
	  pickupAnimation.size = SpriteSize_16x16;
	  pickupDef.spriteID = PICKUP_07;
  
	  TRY(retval = rage.loadSprite(Rage::MAIN, &pickupDef));
	}
      else if(id == PICKUP_08)
	{
	  pickupAnimation.image.gfx = small_pickup08Tiles;
	  pickupAnimation.image.gfxLen = small_pickup08TilesLen;
	  pickupAnimation.image.pal = small_pickup08Pal;
	  pickupAnimation.image.palLen = small_pickup08PalLen;
	  pickupAnimation.size = SpriteSize_16x16;
	  pickupDef.spriteID = PICKUP_08;
  
	  TRY(retval = rage.loadSprite(Rage::MAIN, &pickupDef));
	}
      else if(id == PICKUP_09)
	{
	  pickupAnimation.image.gfx = small_pickup09Tiles;
	  pickupAnimation.image.gfxLen = small_pickup09TilesLen;
	  pickupAnimation.image.pal = small_pickup09Pal;
	  pickupAnimation.image.palLen = small_pickup09PalLen;
	  pickupAnimation.size = SpriteSize_16x16;
	  pickupDef.spriteID = PICKUP_09;
  
	  TRY(retval = rage.loadSprite(Rage::MAIN, &pickupDef));
	}
      else if(id == PICKUP_10)
	{
	  pickupAnimation.image.gfx = small_pickup10Tiles;
	  pickupAnimation.image.gfxLen = small_pickup10TilesLen;
	  pickupAnimation.image.pal = small_pickup10Pal;
	  pickupAnimation.image.palLen = small_pickup10PalLen;
	  pickupAnimation.size = SpriteSize_16x16;
	  pickupDef.spriteID = PICKUP_10;
  
	  TRY(retval = rage.loadSprite(Rage::MAIN, &pickupDef));
	}
      else if(id == PICKUP_11)
	{
	  pickupAnimation.image.gfx = small_pickup11Tiles;
	  pickupAnimation.image.gfxLen = small_pickup11TilesLen;
	  pickupAnimation.image.pal = small_pickup11Pal;
	  pickupAnimation.image.palLen = small_pickup11PalLen;
	  pickupAnimation.size = SpriteSize_16x16;
	  pickupDef.spriteID = PICKUP_11;
  
	  TRY(retval = rage.loadSprite(Rage::MAIN, &pickupDef));
	}
      else if(id == PICKUP_12)
	{
	  pickupAnimation.image.gfx = small_pickup12Tiles;
	  pickupAnimation.image.gfxLen = small_pickup12TilesLen;
	  pickupAnimation.image.pal = small_pickup12Pal;
	  pickupAnimation.image.palLen = small_pickup12PalLen;
	  pickupAnimation.size = SpriteSize_16x16;
	  pickupDef.spriteID = PICKUP_12;
  
	  TRY(retval = rage.loadSprite(Rage::MAIN, &pickupDef));
	}
      else if(id == PICKUP_13)
	{
	  pickupAnimation.image.gfx = small_pickup13Tiles;
	  pickupAnimation.image.gfxLen = small_pickup13TilesLen;
	  pickupAnimation.image.pal = small_pickup13Pal;
	  pickupAnimation.image.palLen = small_pickup13PalLen;
	  pickupAnimation.size = SpriteSize_16x16;
	  pickupDef.spriteID = PICKUP_13;
  
	  TRY(retval = rage.loadSprite(Rage::MAIN, &pickupDef));
	}
      else if(id == PICKUP_14)
	{
	  pickupAnimation.image.gfx = small_pickup14Tiles;
	  pickupAnimation.image.gfxLen = small_pickup14TilesLen;
	  pickupAnimation.image.pal = small_pickup14Pal;
	  pickupAnimation.image.palLen = small_pickup14PalLen;
	  pickupAnimation.size = SpriteSize_16x16;
	  pickupDef.spriteID = PICKUP_14;
  
	  TRY(retval = rage.loadSprite(Rage::MAIN, &pickupDef));
	}
      else if(id == COIN)
	{
#include "graphics/small_coin.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallCoinDef));
	}
      else if(id == GOAL)
	{
#include "graphics/small_goal.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallGoalDef));
	}
      else if(id == BLIP)
	{
#include "graphics/blipdef.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &blipDef));
	}
      else if(id == BLUE_SPARK)
	{
#include "graphics/small_bluespark.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallBlueSparkDef));
	}
      else if(id == RED_SPARK)
	{
#include "graphics/small_redspark.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallRedSparkDef));
	}
      else if(id == BOOTS)
	{
#include "graphics/small_boots.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallBootsDef));
	}
      else if(id == SWEEPER)
	{
#include "graphics/small_sweeper.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallSweeperDef));
	}
      else if(id == TRUNDLER)
	{
#include "graphics/small_trundler.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallTrundlerDef));
	}
      else if(id == TRAPPER)
	{
#include "graphics/small_trapper.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallTrapperDef));
	}
      else if(id == BLOCK_YELLOW)
	{
#include "graphics/small_blocky.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallYellowBlockDef));
	}
      else if(id == BLOCK_GREEN)
	{
#include "graphics/small_blockg.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallGreenBlockDef));
	}
      else if(id == BLOCK_BLUE)
	{
#include "graphics/small_blockb.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallBlueBlockDef));
	}
      else if(id == SWITCH_YELLOW)
	{
#include "graphics/small_switchy.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallYellowSwitchDef));
	}
      else if(id == SWITCH_GREEN)
	{
#include "graphics/small_switchg.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallGreenSwitchDef));
	}
      else if(id == SWITCH_BLUE)
	{
#include "graphics/small_switchb.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallBlueSwitchDef));
	}
      else if(id == TELE_YELLOW)
	{
#include "graphics/small_teley.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallYellowTeleDef));
	}
      else if(id == TELE_GREEN)
	{
#include "graphics/small_teleg.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallGreenTeleDef));
	}
      else if(id == TELE_BLUE)
	{
#include "graphics/small_teleb.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallBlueTeleDef));
	}
      else if(id == TARGET_YELLOW)
	{
#include "graphics/small_teley_target.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallYellowTargetDef));
	}
      else if(id == TARGET_GREEN)
	{
#include "graphics/small_teleg_target.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallGreenTargetDef));
	}
      else if(id == TARGET_BLUE)
	{
#include "graphics/small_teleb_target.h"
	  TRY(retval = rage.loadSprite(Rage::MAIN, &smallBlueTargetDef));
	}
    }
  else if(screen == SUB) // Large sprites
    {      
      if(id == PLAYER)
	{
	  Rage::ImageDefinition player_right;
	  Rage::ImageDefinition player_left;

#include "spr_right_guy1.h"
#include "spr_left_guy1.h"

	  player_right.gfx = spr_right_guy1Tiles;
	  player_right.gfxLen = spr_right_guy1TilesLen;
	  player_right.pal = spr_right_guy1Pal;
	  player_right.palLen = spr_right_guy1PalLen;

	  player_left.gfx = spr_left_guy1Tiles;
	  player_left.gfxLen = spr_left_guy1TilesLen;
	  player_left.pal = spr_left_guy1Pal;
	  player_left.palLen = spr_left_guy1PalLen;

	  {
#include "graphics/playerdef.h"

	    playerAnimations[0].size = SpriteSize_32x32;
	    playerAnimations[1].size = SpriteSize_32x32;
	    playerAnimations[2].size = SpriteSize_32x32;
	    playerAnimations[3].size = SpriteSize_32x32;
	    playerAnimations[4].size = SpriteSize_32x32;
	    playerAnimations[5].size = SpriteSize_32x32;

	    int retval;

	    TRY(retval = rage.loadSprite(Rage::SUB, &playerDef));

	    return retval != 0;
	  }
	}
      else if(id == MARKER)
	{
#include "graphics/large_marker.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeMarkerDef));
	}
      else if(id == BREAKABLE)
	{
#include "graphics/large_breakable.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeBreakableDef));
	}
      else if(id == PICKUP_01)
	{
	  pickupAnimation.image.gfx = large_pickup01Tiles;
	  pickupAnimation.image.gfxLen = large_pickup01TilesLen;
	  pickupAnimation.image.pal = large_pickup01Pal;
	  pickupAnimation.image.palLen = large_pickup01PalLen;
	  pickupAnimation.size = SpriteSize_32x32;
	  pickupDef.spriteID = PICKUP_01;
  
	  TRY(retval = rage.loadSprite(Rage::SUB, &pickupDef));
	}
      else if(id == PICKUP_02)
	{
	  pickupAnimation.image.gfx = large_pickup02Tiles;
	  pickupAnimation.image.gfxLen = large_pickup02TilesLen;
	  pickupAnimation.image.pal = large_pickup02Pal;
	  pickupAnimation.image.palLen = large_pickup02PalLen;
	  pickupAnimation.size = SpriteSize_32x32;
	  pickupDef.spriteID = PICKUP_02;
  
	  TRY(retval = rage.loadSprite(Rage::SUB, &pickupDef));
	}
      else if(id == PICKUP_03)
	{
	  pickupAnimation.image.gfx = large_pickup03Tiles;
	  pickupAnimation.image.gfxLen = large_pickup03TilesLen;
	  pickupAnimation.image.pal = large_pickup03Pal;
	  pickupAnimation.image.palLen = large_pickup03PalLen;
	  pickupAnimation.size = SpriteSize_32x32;
	  pickupDef.spriteID = PICKUP_03;
  
	  TRY(retval = rage.loadSprite(Rage::SUB, &pickupDef));
	}
      else if(id == PICKUP_04)
	{
	  pickupAnimation.image.gfx = large_pickup04Tiles;
	  pickupAnimation.image.gfxLen = large_pickup04TilesLen;
	  pickupAnimation.image.pal = large_pickup04Pal;
	  pickupAnimation.image.palLen = large_pickup04PalLen;
	  pickupAnimation.size = SpriteSize_32x32;
	  pickupDef.spriteID = PICKUP_04;
  
	  TRY(retval = rage.loadSprite(Rage::SUB, &pickupDef));
	}
      else if(id == PICKUP_05)
	{
	  pickupAnimation.image.gfx = large_pickup05Tiles;
	  pickupAnimation.image.gfxLen = large_pickup05TilesLen;
	  pickupAnimation.image.pal = large_pickup05Pal;
	  pickupAnimation.image.palLen = large_pickup05PalLen;
	  pickupAnimation.size = SpriteSize_32x32;
	  pickupDef.spriteID = PICKUP_05;
  
	  TRY(retval = rage.loadSprite(Rage::SUB, &pickupDef));
	}
      else if(id == PICKUP_06)
	{
	  pickupAnimation.image.gfx = large_pickup06Tiles;
	  pickupAnimation.image.gfxLen = large_pickup06TilesLen;
	  pickupAnimation.image.pal = large_pickup06Pal;
	  pickupAnimation.image.palLen = large_pickup06PalLen;
	  pickupAnimation.size = SpriteSize_32x32;
	  pickupDef.spriteID = PICKUP_06;
  
	  TRY(retval = rage.loadSprite(Rage::SUB, &pickupDef));
	}
      else if(id == PICKUP_07)
	{
	  pickupAnimation.image.gfx = large_pickup07Tiles;
	  pickupAnimation.image.gfxLen = large_pickup07TilesLen;
	  pickupAnimation.image.pal = large_pickup07Pal;
	  pickupAnimation.image.palLen = large_pickup07PalLen;
	  pickupAnimation.size = SpriteSize_32x32;
	  pickupDef.spriteID = PICKUP_07;
  
	  TRY(retval = rage.loadSprite(Rage::SUB, &pickupDef));
	}
      else if(id == PICKUP_08)
	{
	  pickupAnimation.image.gfx = large_pickup08Tiles;
	  pickupAnimation.image.gfxLen = large_pickup08TilesLen;
	  pickupAnimation.image.pal = large_pickup08Pal;
	  pickupAnimation.image.palLen = large_pickup08PalLen;
	  pickupAnimation.size = SpriteSize_32x32;
	  pickupDef.spriteID = PICKUP_08;
  
	  TRY(retval = rage.loadSprite(Rage::SUB, &pickupDef));
	}
      else if(id == PICKUP_09)
	{
	  pickupAnimation.image.gfx = large_pickup09Tiles;
	  pickupAnimation.image.gfxLen = large_pickup09TilesLen;
	  pickupAnimation.image.pal = large_pickup09Pal;
	  pickupAnimation.image.palLen = large_pickup09PalLen;
	  pickupAnimation.size = SpriteSize_32x32;
	  pickupDef.spriteID = PICKUP_09;
  
	  TRY(retval = rage.loadSprite(Rage::SUB, &pickupDef));
	}
      else if(id == PICKUP_10)
	{
	  pickupAnimation.image.gfx = large_pickup10Tiles;
	  pickupAnimation.image.gfxLen = large_pickup10TilesLen;
	  pickupAnimation.image.pal = large_pickup10Pal;
	  pickupAnimation.image.palLen = large_pickup10PalLen;
	  pickupAnimation.size = SpriteSize_32x32;
	  pickupDef.spriteID = PICKUP_10;
  
	  TRY(retval = rage.loadSprite(Rage::SUB, &pickupDef));
	}
      else if(id == PICKUP_11)
	{
	  pickupAnimation.image.gfx = large_pickup11Tiles;
	  pickupAnimation.image.gfxLen = large_pickup11TilesLen;
	  pickupAnimation.image.pal = large_pickup11Pal;
	  pickupAnimation.image.palLen = large_pickup11PalLen;
	  pickupAnimation.size = SpriteSize_32x32;
	  pickupDef.spriteID = PICKUP_11;
  
	  TRY(retval = rage.loadSprite(Rage::SUB, &pickupDef));
	}
      else if(id == PICKUP_12)
	{
	  pickupAnimation.image.gfx = large_pickup12Tiles;
	  pickupAnimation.image.gfxLen = large_pickup12TilesLen;
	  pickupAnimation.image.pal = large_pickup12Pal;
	  pickupAnimation.image.palLen = large_pickup12PalLen;
	  pickupAnimation.size = SpriteSize_32x32;
	  pickupDef.spriteID = PICKUP_12;
  
	  TRY(retval = rage.loadSprite(Rage::SUB, &pickupDef));
	}
      else if(id == PICKUP_13)
	{
	  pickupAnimation.image.gfx = large_pickup13Tiles;
	  pickupAnimation.image.gfxLen = large_pickup13TilesLen;
	  pickupAnimation.image.pal = large_pickup13Pal;
	  pickupAnimation.image.palLen = large_pickup13PalLen;
	  pickupAnimation.size = SpriteSize_32x32;
	  pickupDef.spriteID = PICKUP_13;
  
	  TRY(retval = rage.loadSprite(Rage::SUB, &pickupDef));
	}
      else if(id == PICKUP_14)
	{
	  pickupAnimation.image.gfx = large_pickup14Tiles;
	  pickupAnimation.image.gfxLen = large_pickup14TilesLen;
	  pickupAnimation.image.pal = large_pickup14Pal;
	  pickupAnimation.image.palLen = large_pickup14PalLen;
	  pickupAnimation.size = SpriteSize_32x32;
	  pickupDef.spriteID = PICKUP_14;
  
	  TRY(retval = rage.loadSprite(Rage::SUB, &pickupDef));
	}
      else if(id == COIN)
	{
#include "graphics/large_coin.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeCoinDef));
	}
      else if(id == GOAL)
	{
#include "graphics/large_goal.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeGoalDef));
	}
      else if(id == BLUE_SPARK)
	{
#include "graphics/large_bluespark.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeBlueSparkDef));
	}
      else if(id == RED_SPARK)
	{
#include "graphics/large_redspark.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeRedSparkDef));
	}
      else if(id == BOOTS)
	{
#include "graphics/large_boots.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeBootsDef));
	}
      else if(id == SWEEPER)
	{
#include "graphics/large_sweeper.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeSweeperDef));
	}
      else if(id == TRUNDLER)
	{
#include "graphics/large_trundler.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeTrundlerDef));
	}
      else if(id == TRAPPER)
	{
#include "graphics/large_trapper.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeTrapperDef));
	}
      else if(id == BLOCK_YELLOW)
	{
#include "graphics/large_blocky.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeYellowBlockDef));
	}
      else if(id == BLOCK_GREEN)
	{
#include "graphics/large_blockg.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeGreenBlockDef));
	}
      else if(id == BLOCK_BLUE)
	{
#include "graphics/large_blockb.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeBlueBlockDef));
	}
      else if(id == SWITCH_YELLOW)
	{
#include "graphics/large_switchy.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeYellowSwitchDef));
	}
      else if(id == SWITCH_GREEN)
	{
#include "graphics/large_switchg.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeGreenSwitchDef));
	}
      else if(id == SWITCH_BLUE)
	{
#include "graphics/large_switchb.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeBlueSwitchDef));
	}
      else if(id == TELE_YELLOW)
	{
#include "graphics/large_teley.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeYellowTeleDef));
	}
      else if(id == TELE_GREEN)
	{
#include "graphics/large_teleg.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeGreenTeleDef));
	}
      else if(id == TELE_BLUE)
	{
#include "graphics/large_teleb.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeBlueTeleDef));
	}
      else if(id == TARGET_YELLOW)
	{
#include "graphics/large_teley_target.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeYellowTargetDef));
	}
      else if(id == TARGET_GREEN)
	{
#include "graphics/large_teleg_target.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeGreenTargetDef));
	}
      else if(id == TARGET_BLUE)
	{
#include "graphics/large_teleb_target.h"
	  TRY(retval = rage.loadSprite(Rage::SUB, &largeBlueTargetDef));
	}
    }

  if(retval != 0)
    {
      spriteLoaded[screen == MAIN ? 0 : 1][id] = true;
    }

  return retval != 0;
}

bool
DataManager::loadTileSet(Screen screen, int id)
{
  int retval = 0;

  if(tileSetLoaded[screen == MAIN ? 0 : 1][id])
    return true;

  Rage::Screen scr = screen == MAIN ? Rage::MAIN : Rage::SUB;

  switch(id)
    {
    case SMALL_TILES:
      {
#include "graphics/tilessmalldef.h"
	TRY(retval = rage.loadTileSet(scr, &tilesSmallDef));
      }
      break;

    case LARGE_TILES:
      {
#include "graphics/tilesdef.h"
	TRY(retval = rage.loadTileSet(scr, &tilesDef));
      }
      break;

    case BG_MAIN:
      {
#include "graphics/bgmaindef.h"
	TRY(retval = rage.loadTileSet(scr, &bgMainDef));
      }
      break;

    case BORDER:
      {
#include "graphics/borderdef.h"
	TRY(retval = rage.loadTileSet(scr, &borderDef));
      }
    }

  if(retval != 0)
    {
      tileSetLoaded[screen == MAIN ? 0 : 1][id] = true;
    }

  return retval != 0;
}

void
DataManager::unloadGraphics()
{
  rage.unloadAllSprites(Rage::MAIN);
  rage.unloadAllSprites(Rage::SUB);
  rage.unloadAllTileSets(Rage::MAIN);
  rage.unloadAllTileSets(Rage::SUB);

  clearLoadedInfo();
}

void
DataManager::setSelectedLevel(int set, int level)
{
  this->set = set;
  this->level = level;
}

int
DataManager::getSelectedSet()
{
  return set;
}

LevelData
DataManager::getLevelData()
{
  if(set >= 0 && set <= 3 && level >= 0 && level <= 11)
    return levels[set][level];

  return nullLevel;
}

bool
DataManager::saveLevelCleared()
{
  levels[set][level].cleared = true;

  return true;
}

bool
DataManager::getLevelCleared(int set, int level)
{
  if(set >= 0 && set <= 3 && level >= 0 && level <= 11)
    return levels[set][level].cleared;

  return false;
}

bool
DataManager::getSetUnlocked(int set)
{
  if(set >= 0 && set <= 3)
    return setUnlocked[set];

  return false;
}

void
DataManager::initLevelData()
{
  nullLevel.data = 0;
  nullLevel.length = 0;
  nullLevel.cleared = false;

  setUnlocked[0] = true;
  setUnlocked[1] = false;
  setUnlocked[2] = false;
  setUnlocked[3] = false;

  for(int y = 0;y < 4;y++)
    for(int x = 0;x < 12;x++)
      levels[y][x] = nullLevel;

  levels[0][0].data = level_1_01_bin;
  levels[0][0].length = level_1_01_bin_size;

  levels[0][1].data = level_1_02_bin;
  levels[0][1].length = level_1_02_bin_size;

  levels[0][2].data = level_1_03_bin;
  levels[0][2].length = level_1_03_bin_size;

  levels[0][3].data = level_1_04_bin;
  levels[0][3].length = level_1_04_bin_size;

  levels[0][4].data = level_1_05_bin;
  levels[0][4].length = level_1_05_bin_size;

  levels[0][5].data = level_1_06_bin;
  levels[0][5].length = level_1_06_bin_size;

  levels[0][6].data = level_1_07_bin;
  levels[0][6].length = level_1_07_bin_size;

  levels[0][7].data = level_1_08_bin;
  levels[0][7].length = level_1_08_bin_size;

  levels[0][8].data = level_1_09_bin;
  levels[0][8].length = level_1_09_bin_size;

  levels[0][9].data = level_1_10_bin;
  levels[0][9].length = level_1_10_bin_size;

  levels[0][10].data = level_1_11_bin;
  levels[0][10].length = level_1_11_bin_size;

  levels[0][11].data = level_1_12_bin;
  levels[0][11].length = level_1_12_bin_size;
}

void
DataManager::clearLoadedInfo()
{
  for(int i = 0;i < LAST_SPRITE;i++)
    {
      spriteLoaded[0][i] = false;
      spriteLoaded[1][i] = false;
    }

  for(int i = 0;i < LAST_TILESET;i++)
    {
      tileSetLoaded[0][i] = false;
      tileSetLoaded[1][i] = false;
    }
}
