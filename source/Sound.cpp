#include "Sound.h"

#include <nds.h>
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

#include "sounds.h"

#define NR_EFFECTS 5
mm_sound_effect effects[NR_EFFECTS];

Sound::Sound()
{
  mmInitDefaultMem((mm_addr)soundbank_bin);
  mmLoad(MOD_CASTLE_MUSIC);
  mmStart(MOD_CASTLE_MUSIC, MM_PLAY_LOOP);

  initEffects();
}

void
Sound::play(int s)
{
  mmEffectEx(&effects[s]);
}

void
Sound::initEffects()
{
  int s[] = {SFX_JUMP, SFX_COIN, SFX_BRICK, SFX_PLACE, SFX_DESTROY};

  for(int i = 0;i < NR_EFFECTS;i++)
    {
      effects[i].id = s[i];
      effects[i].rate = (1<<10);
      effects[i].handle = 0;
      effects[i].volume = 255;
      effects[i].panning = 127;

      mmLoadEffect(s[i]);
    }
}
