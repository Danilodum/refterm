#define REFTERM_VERSION 2

#if _DEBUG
#define Assert(cond) do { if (!(cond)) __debugbreak(); } while (0)
#define DebugLog(format, ...) do { \
    char debug_buffer[1024]; \
    wsprintfA(debug_buffer, "[REFTERM] " format "\n", __VA_ARGS__); \
    OutputDebugStringA(debug_buffer); \
} while(0)
#else
#define Assert(cond)
#define DebugLog(format, ...)
#endif

#define AssertHR(hr) Assert(SUCCEEDED(hr))
#define ArrayCount(Array) (sizeof(Array) / sizeof((Array)[0]))

#define IsPowerOfTwo(Value) (((Value) & ((Value) - 1)) == 0)
#define SafeRatio1(A, B) ((B) ? ((A)/(B)) : (A))
