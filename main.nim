import ioutils

type
  TMultiboot_header = object
  PMultiboot_header = ptr TMultiboot_header

# type
#   FileSystem* = object
#     names*: array[10, cstring]

# var filesystem: FileSystem = FileSystem()
# filesystem.names[0] = cstring"a"
# var line = 1

# # credit to dom96
# template print(code: string): untyped =
#   writeString(vram, code, attr, (line, 0))
#   line += 1

# proc run(code: cstring, vram: PVidMem, attr: TAttribute) =
#   if code == cstring"help":
#     print "Praise the Lord!"
#     print "lodka 0.1"
#   elif code == cstring"ls":
#     print "a" #$filesystem.names[0]

proc input: cstring =
  cstring"ls"

proc repl =
  var vram = cast[PVIDMem](0xB8000)
  let attr = makeColor(Black, White)
  writeString(vram, "> ", attr, (0, 0))
  let code = input()
  # run(code, vram, attr)

# fork of nimkernel: maybe we will! add mero and credit for now no!

proc kmain(mb_header: PMultiboot_header, magic: int) {.exportc.} =
  if magic != 0x2BADB002:
    discard # Something went wrong?

  var vram = cast[PVIDMem](0xB8000)
  # screenClear(vram, Yellow) # Make the screen yellow.

  # # Demonstration of error handling.
  # var x = len(vram[])
  # var outOfBounds = vram[x]
  # writeChar(vram, 'a'.TEntry, (25, 9))
  # let attr = makeColor(Yellow, DarkGrey)
  # writeString(vram, "Nim", attr, (25, 9))
  # let e = "0"
  # writeString(vram, "ok", attr, (25, 10))
  # repl()
