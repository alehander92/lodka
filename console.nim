# from dom96 nimkernel

type
  TVGAColor* = enum
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGrey = 7,
    DarkGrey = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15

  Color* = TVGAColor

const 
  textColor* = Blue
  screenColor* = White

# based on dom96 nimkernel
var vram*: ptr array[0 .. 130_000, char]
var 
  consoleX*: int
  consoleY*: int

proc screenClear*(color: Color) =
  var c= '_'
  
  var i = 0
  while i <= 160 * 25:
    vram[i] = c
    vram[i + 1] = 255.char #((color.int8 shr 4) or (1'i8 and 0x0f)).char
    i += 2
  
proc writeChar*(a: char, x: int, y: int) =
  vram[160 * x + y] = a
  vram[160 * x + y + 1] = (240 or textColor.int).char 

proc writeString*(a: string, x: int, y: int) =
  for b in 0 ..< a.len:
    writeChar(a[b], x, y + b * 2)

proc consoleWrite*(a: string) =
  writeString(a, consoleX, consoleY)
  consoleY += a.len

proc consoleWriteNl*(a: string) =
  writeString(a, consoleX, consoleY)
  consoleX += 1
  consoleY = 0


