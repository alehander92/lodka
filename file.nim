
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


# file("/", @[file("a", ""), file("b", "")])
proc file*(name: string, text: string): owned File =
  File(kind: FileText, name: name, text: text)

proc file*(name: string, children: seq[File]): owned File =
  var file = File(kind: FileDirectory, name: name, parent: nil, children: children)
  for child in file.children:
    child.parent = file
  return file



proc repl =  
  consoleWrite("> ")

proc sleep(ms: int) =
  # simple
  var index = 0
  for i in 0 ..< ms * 50_000:
    index += 1

proc ls(context: Context) =
  consoleWrite("> ")
  consoleWriteNl(context.filesystem.current.name)
  for child in context.filesystem.current.children:
    consoleWriteNl(child.name)
  consoleWriteNl("")
