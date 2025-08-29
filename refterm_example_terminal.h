enum
{
    TerminalCell_Bold = 0x1,
    TerminalCell_Dim = 0x2,
    TerminalCell_Italic = 0x4,
    TerminalCell_Underline = 0x8,
    TerminalCell_Blinking = 0x10,
    TerminalCell_ReverseVideo = 0x20,
    TerminalCell_Invisible = 0x40,
    TerminalCell_Strikethrough = 0x80,
};

typedef struct
{
    renderer_cell *Cells;
    uint32_t DimX, DimY;
    uint32_t FirstLineY;
} terminal_buffer;

typedef struct
{
    int32_t X, Y;
} terminal_point;

typedef struct
{
    uint32_t Foreground;
    uint32_t Background;
    uint32_t Flags;
} glyph_props;

typedef struct
{
    terminal_point At;
    glyph_props Props;
} cursor_state;


typedef struct
{
    kbts_break_state BreakState;
    DWORD SegP[1026]; // Array for segments (compatible with original segment structure)
    uint32_t SegmentCount;
} kb_partitioner;

typedef struct
{
    size_t FirstP;
    size_t OnePastLastP;
    uint32_t ContainsComplexChars;
    glyph_props StartingProps;
} example_line;

typedef struct
{
    HWND Window;
    int Quit;

    d3d11_renderer Renderer;
    glyph_generator GlyphGen;
    void *GlyphTableMem;
    glyph_table *GlyphTable;
    terminal_buffer ScreenBuffer;
    source_buffer ScrollBackBuffer;
    kb_partitioner KBPartitioner;

    DWORD PipeSize;

    HANDLE Legacy_WriteStdIn;
    HANDLE Legacy_ReadStdOut;
    HANDLE Legacy_ReadStdError;

    int EnableFastPipe;
    HANDLE FastPipeReady;
    HANDLE FastPipe;
    OVERLAPPED FastPipeTrigger;

    HANDLE ChildProcess;

    cursor_state RunningCursor;

    wchar_t LastChar;
    uint32_t CommandLineCount;
    char CommandLine[256];

    int NoThrottle;
    int DebugHighlighting;

    uint32_t MaxLineCount;
    uint32_t CurrentLineIndex;
    uint32_t LineCount;
    example_line *Lines;

    int32_t ViewingLineOffset;

    wchar_t RequestedFontName[64];
    uint32_t RequestedFontHeight;
    int LineWrap;

    uint32_t DefaultForegroundColor;
    uint32_t DefaultBackgroundColor;

    uint32_t REFTERM_TEXTURE_WIDTH;
    uint32_t REFTERM_TEXTURE_HEIGHT;

    uint32_t TransferWidth;
    uint32_t TransferHeight;

    uint32_t REFTERM_MAX_WIDTH;
    uint32_t REFTERM_MAX_HEIGHT;

#define MinDirectCodepoint 32
#define MaxDirectCodepoint 126
    gpu_glyph_index ReservedTileTable[MaxDirectCodepoint - MinDirectCodepoint + 1];
} example_terminal;

