#if !defined(HANDMADE_H)

/*
	TODO(spike): services that the game provides to the platform layer 
*/

/*
	services that the platform layer provides to the game.
    (this may expand in the future - sound on separate thread, etc.)
*/

struct game_offscreen_buffer
{
    void *Memory;
    int Width;
    int Height;
	int Pitch;
};

internal void GameUpdateAndRender(game_offscreen_buffer *Buffer, int BlueOffset, int GreenOffset);

#define HANDMADE_H
#endif
