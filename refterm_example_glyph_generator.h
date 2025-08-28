typedef enum
{
    GlyphState_None,
    GlyphState_Sized,
    GlyphState_Rasterized,
} glyph_entry_state;

typedef struct glyph_generator glyph_generator;
typedef struct glyph_dim glyph_dim;

struct glyph_dim
{
    uint32_t TileCount;
    float XScale, YScale;
};

struct glyph_generator
{
    uint32_t FontWidth, FontHeight;
    uint32_t Pitch;
    uint32_t *Pixels;
    
    uint32_t TransferWidth;
    uint32_t TransferHeight;
    
    // NOTE(casey): For DWrite-based generation:
    struct IDWriteFactory *DWriteFactory;
    struct IDWriteFontFace *FontFace;
    struct IDWriteTextFormat *TextFormat;
    
    // NOTE: For kb_text_shape integration:
    char FontFilePath[260];    // MAX_PATH - Store resolved font file path
    int HasFontFile;           // Flag indicating if font file path is available
};
