# Praise God ! ! !



{.experimental:"codeReordering".}
## based on mero and nimkernel for now
## a kernel module

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
    scheduler: Scheduler


  Scheduler* = ref object
    processes*: seq[Process]
    context*:   Context
    currentProcess*: int

  Process* = ref object
    name*:      string
    # function*:  proc(context: Context)
    registers*: Registers
    id*:        int


  Registers* = object


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

proc switchTasks(a: Registers, b: Registers) {.importc.}



proc switchTasks*(scheduler: Scheduler) =
  ## a function which switches tasks: for multitasking
  ## cant doc
  var process = scheduler.processes[scheduler.currentProcess]
  var nextProcess = scheduler.processes[if scheduler.currentProcess == 0: 1 else: 0] # TODO m
  scheduler.currentProcess = nextProcess.id
  switchTasks(process.registers, nextProcess.registers)


template cooperate {.dirty.} =
  switchTasks(context.scheduler)

proc a(context: Context) =
  var i = 0
  while true:
    sleep(1_000)
    cooperate
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
    cooperate
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
  install()
  {.emit: """
  __asm__ __volatile__ ("sti");
  """.}

  consoleWriteNl("welcome")
  
  # var scheduler = initScheduler()
  # var context = Context(filesystem: Filesystem(root: file("/", @[file("a", ""), file("b", "")])), scheduler: scheduler)
  # context.filesystem.current = context.filesystem.root
  # context.scheduler.schedule(context)
  # ls(context)  

  # context.scheduler.register(0)
  # context.scheduler.register(1)
  # context.scheduler.run()
  # a(context)
  # var a0 = context.scheduler
  # switchTasks(a0)

# kmain(nil, 0)

# if God decides!

# simple multitask between "functions" or objects
# some chess
# some talk tahchiev

proc install {.exportc.} =
  # from mero
  consoleWriteNl("install")
  gdtInstall()
  idtInstall()
  isrsInstall()
  irqInstall()
  keyboardInstall()
  

# based on mero
proc fault_handler(regs: ptr registers) {.exportc.} =
  #Handle isr

  discard
  # #If it's an exception...
  # if regs.int_no < 32:
  #   #Halt and notify the user
  #   consoleWriteNl("================================================================================")
  #   consoleWrite("Got exception ")
  #   # consoleWriteNl(regs.int_no)
  #   consoleWrite(": ")
  #   consoleWriteNl(exceptionMessages[regs.int_no])
  #   consoleWriteNl("================================================================================")
  #   # writeRegisters(regs)
  #   # panic("EXCEPTION!!!!")
  

proc initScheduler: owned Scheduler =
  Scheduler()

proc schedule(scheduler: Scheduler, context: Context) =
  scheduler.context = context
  consoleWriteNl("schedule")

proc register(scheduler: Scheduler, id: int) =
  consoleWriteNl("function")
  var process = Process(id: id)
  if id == 0:
    process.name = "a"
  else:
    process.name = "b"
  
  scheduler.processes.add(process)
  # function(scheduler.context)

proc run*(scheduler: Scheduler) =
  let id = scheduler.processes[0].id
  # if id == 0:
  # a(scheduler.context)
  # else:
  #   b(scheduler.context)

