# Praise God ! ! !



{.experimental:"codeReordering".}
# based on mero and nimkernel for now

import Mero / source / [asmwrapper, merosystem, isrs, irq, gdt, idt, math, keyboard], console

type
  Filesystem = ref object
    root*: File
    current*: File

  FileKind* = enum FileDirectory, FileText

  File = ref object
    name*: string
    parent*: File
    case kind*: FileKind:
      of FileDirectory:
        children*: seq[File]
      else:
        text*: string

  Context = ref object
    filesystem: Filesystem


  Scheduler* = ref object
    processes*: seq[Process]
    context*:   Context

  Process* = ref object
    name*:      string
    function*:  proc(context: Context)

# // fork of nimkernel: maybe we will! add mero and credit for now no!


# file("/", @[file("a", ""), file("b", "")])
proc file*(name: string, text: string): owned File =
  File(kind: FileText, name: name, text: text)

proc file*(name: string, children: seq[File]): owned File =
  var file = File(kind: FileDirectory, name: name, parent: nil, children: children)
  for child in file.children:
    child.parent = file
  return file

# one program, no multitasking
# but how does it run? e.g. a server build: ok

proc repl =  
  consoleWrite("> ")

proc sleep(ms: int) =
  # simple
  var index = 0
  for i in 0 ..< ms * 50_000:
    index += 1

# after each while insert a "yield" and make it an object
# multitask just calls th
# and then starts calling iteration on them .. hm, but how to preserve state ..
# iterators .. lets try and see how hard without event loop
#
# iterator a() .. yield
# for (aSlice, bSlice) in zip(a, b):
#   discard

# but then how scheduler?
# scheduler just remembers the stack and replaces it ..

# a.call() # it returns true or false and if false we copy the stack and stuff and wait
# next call it again

proc a(context: Context) =
  var i = 0
  while true:
    sleep(1_000)
    var t = ""
    if i mod 2 == 0:
      t = "0"
    else:
      t = "1"
    writeString(t, 7, 0)
    i += 1
    
proc b(context: Context) =
  var i = 0
  while true:
    sleep(1_000)
    var t = ""
    if i mod 2 == 0:
      t = "2"
    else:
      t = "3"
    writeString(t, 7, 0)
    i += 1

proc ls(context: Context) =
  consoleWrite("> ")
  consoleWriteNl(context.filesystem.current.name)
  for child in context.filesystem.current.children:
    consoleWriteNl(child.name)
  consoleWriteNl("")


proc kmain*(header: pointer, b2: int) {.exportc.} =

  # Praise God ! ! !
  
  

  vram = cast[ptr array[0 .. 130_000, char]](0xB8000)
  consoleX = 1
  consoleY = 0
  screenClear(screenColor)
  consoleWriteNl("welcome")
  keyboardInstall()
  var context = Context(filesystem: Filesystem(root: file("/", @[file("a", ""), file("b", "")])))
  context.filesystem.current = context.filesystem.root
  ls(context)  

  var scheduler = initScheduler()
  scheduler.schedule(context)
  # scheduler.start(a)
  # scheduler.start(b)

# kmain(nil, 0)

# if God decides!

# simple multitask between "functions" or objects
# some chess
# some talk tahchiev

proc install {.exportc.} =
  # from mero
  gdtInstall()
  idtInstall()
  isrsInstall()
  irqInstall()

# based on mero
proc fault_handler(regs: ptr registers) {.exportc.} =
  #Handle isr

  #If it's an exception...
  if regs.int_no < 32:
    #Halt and notify the user
    consoleWriteNl("================================================================================")
    consoleWrite("Got exception ")
    # consoleWriteNl(regs.int_no)
    consoleWrite(": ")
    consoleWriteNl(exceptionMessages[regs.int_no])
    consoleWriteNl("================================================================================")
    # writeRegisters(regs)
    # panic("EXCEPTION!!!!")
  

proc initScheduler: owned Scheduler =
  Scheduler()

proc schedule(scheduler: Scheduler, context: Context) =
  scheduler.context = context
  consoleWriteNl("schedule")

proc start(scheduler: Scheduler, function: proc(context: Context)) =
  consoleWriteNl("function")
  function(scheduler.context)

