# Praise God !!!




## based on mero and nimkernel for now: a fork of them 
## a kernel module
## 
{.experimental:"codeReordering".}

# import Mero / source / [asmwrapper, merosystem, isrs, irq, gdt, idt, math, keyboard], console
import console


proc setup =
  gdtInstall()
  idtInstall()

proc kmain*(header: pointer, b2: int) {.exportc.} = 
  vram = cast[ptr array[0 .. 130_000, char]](0xB8000)
  let h = 'h'.char # L
  vram[0] = h
  vram[1] = ((White.int8 shr 4) or (Red.int8 and 0x0f)).char
  screenClear(screenColor)
  consoleWriteNl("love")
  var help = "help"
  consoleWriteNl(help)
  var list = @["help"]
  consoleWriteNl(list[0])
  setup()

  # {.emit: """
  # __asm__ __volatile__ ("sti");
  # """.}


# letter color 
# 76 => L 0xAA0000 => red