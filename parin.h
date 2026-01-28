typedef struct {
    unsigned long length;
    char *ptr;
} IStr;

typedef struct {
    float x, y;
} Vec2;

typedef struct {
    unsigned char r, g, b, a;
} Rgba;

typedef unsigned char Hook;
typedef unsigned char Flip;
typedef unsigned char Alignment;

typedef struct {
    Vec2 origin;         /// The origin point of the drawn object. This value can be used to force a specific origin.
    Vec2 scale;          /// The scale of the drawn object.
    float rotation;      /// The rotation of the drawn object, in degrees.
    Rgba color;          /// The color of the drawn object, in RGBA.
    Hook hook;           /// A value representing the origin point of the drawn object when origin is zero.
    Flip flip;           /// A value representing flipping orientations.
    unsigned char layer; /// A value that can be used by depth sorting functions.
} DrawOptions;

typedef struct {
    float visibilityRatio;          /// Controls the visibility ratio of the text when visibilityCount is zero, where 0.0 means fully hidden and 1.0 means fully visible.
    int alignmentWidth;             /// The width of the aligned text. It is used as a hint and is not enforced.
    unsigned short visibilityCount; /// Controls the visibility count of the text. This value can be used to force a specific character count.
    Alignment alignment;            /// A value represeting alignment orientations.
    unsigned char isRightToLeft;    /// Indicates whether the content of the text flows in a right-to-left direction.
} TextOptions;

void prOpenWindow(int width, int height, int argc, char **argv, char *title, unsigned char vsync);
void prUpdateWindow(void *updateFunc, void *debugModeFunc, void *debugModeBeginFunc, void *debugModeEndFunc);
void prCloseWindow();

Vec2 prDrawText(IStr text, Vec2 position, DrawOptions options, TextOptions extra);
Vec2 prMouse();
