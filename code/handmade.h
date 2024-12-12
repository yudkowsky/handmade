#if !defined(HANDMADE_H)

/*
	TODO(spike): services that the game provides to the platform layer 
*/

/*
	services that the platform layer provides to the game.
    (this may expand in the future - sound on separate thread, etc.)
*/

// TODO(spike): in the future, rendering _specifically_ will become a three-tiered abstraction
struct game_offscreen_buffer
{
    void *Memory;
    int Width;
    int Height;
	int Pitch;
};

struct game_sound_output_buffer 
{
    int SamplesPerSecond;
    int SampleCount;
    int16 *Samples;
};

internal void GameUpdateAndRender(game_offscreen_buffer *Buffer, int BlueOffset, int GreenOffset, 
        						  game_sound_output_buffer *SoundBuffer);

#define HANDMADE_H
#endif
