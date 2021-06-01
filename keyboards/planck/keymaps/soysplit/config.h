#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

// from qmk audio stuff
#define AUDIO_CLICKY

// for the unicode stuff
#define UNICODE_SELECTED_MODES UC_WINC, UC_MAC, UC_LNX

#define MK_3_SPEED

#define TAPPING_TERM 150 // originally was 200. 150 is really low but i can manage if i am fast it is mostly the alt keys that i am too slow with i think i push my pinkeys too far however this can be impoved.
#define IGNORE_MOD_TAP_INTERRUPT