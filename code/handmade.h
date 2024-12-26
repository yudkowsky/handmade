#if !defined(HANDMADE_H)
/*
HANDMADE_INTERNAL:
	0 - Build for release
    1 - Build for dev only

HANDMADE_SLOW:
	0 - No slow code allowed!
    1 - Slow code welcome
*/ 

#if HANDMADE_SLOW 
// TODO(spike): complete assertion macro
#define Assert(Expression) if (!(Expression)) {*(int *)0 = 0;}
#else
#define Assert(Expression)
#endif

#define Kilobytes(Value) ((Value)*1024LL)
#define Megabytes(Value) (Kilobytes(Value)*1024LL)
#define Gigabytes(Value) (Megabytes(Value)*1024LL)
#define Terabytes(Value) (Gigabytes(Value)*1024LL)

#define ArrayCount(Array) (sizeof(Array) / sizeof((Array)[0]))
// TODO(spike): swap, min, max ... macros?

inline uint32
SafeTruncateUInt64(uint64 Value)
{
    // TODO(spike): defines for maximum values 
    Assert(Value <= 0xFFFFFFFF);
    uint32 Result = (uint32)Value;
	return Result;
}

/*
	services that the game provides to the platform layer 
*/
#if HANDMADE_INTERNAL
internal void *DEBUGPlatformReadEntireFile(char *Filename);
internal void DEBUGPlatformFreeFileMemory(void *Memory);
internal bool32 DEBUGPlatformWriteEntireFile(char *Filename, uint32 MemorySize, void *Memory);
#endif

/*
	services that the platform layer provides to the game.
    (this may expand in the future - sound on separate thread, etc.)
*/

// TODO(spike): in the future, rendering _specifically_ will become a three-tiered abstraction
struct game_sound_output_buffer 
{
    int SamplesPerSecond;
    int SampleCount;
    int16 *Samples;
};

struct game_offscreen_buffer
{
    void *Memory;
    int Width;
    int Height;
	int Pitch;
};

struct game_button_state
{
	int HalfTransitionCount;
	bool32 EndedDown;
};

struct game_controller_input
{
    bool32 IsAnalog;

	real32 StartX;
	real32 StartY;

	real32 MinX;
	real32 MinY;

	real32 MaxX;
	real32 MaxY;

    real32 EndX;
    real32 EndY;

    union
    {
        game_button_state Buttons[6];
        struct
        {
            game_button_state Up;
            game_button_state Down;
            game_button_state Left;
            game_button_state Right;
            game_button_state LeftShoulder;
            game_button_state RightShoulder;
        };
    };
};

struct game_input
{
    // TODO(spike): insert clock value here
    game_controller_input Controllers[4];
};

struct game_memory
{
    bool32 IsInitialised;

	uint64 PermanentStorageSize;
    void *PermanentStorage; // required to be cleared to zero at startup

	uint64 TransientStorageSize;
    void *TransientStorage; // required to be cleared to zero at startup
};

internal void
GameUpdateAndRender(game_memory *Memory, game_input *Input, game_offscreen_buffer *Buffer, game_sound_output_buffer *SoundBuffer);

//
//
//

struct game_state
{
    int ToneHz;
    int GreenOffset;
    int BlueOffset;
};

#define HANDMADE_H
#endif
