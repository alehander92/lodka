import tty
import merosystem, isrs, irq, math
import timer, keyboard
import paging

#TODO: This is out of date???
discard """
The multiboot spec from: https://www.gnu.org/software/grub/manual/multiboot/multiboot.html
follows for reference.
The layout of the Multiboot header must be as follows:

Offset 	Type 	Field Name 	Note
0 	u32 	magic 	required
4 	u32 	flags 	required
8 	u32 	checksum 	required
12 	u32 	header_addr 	if flags[16] is set
16 	u32 	load_addr 	if flags[16] is set
20 	u32 	load_end_addr 	if flags[16] is set
24 	u32 	bss_end_addr 	if flags[16] is set
28 	u32 	entry_addr 	if flags[16] is set
32 	u32 	mode_type 	if flags[2] is set
36 	u32 	width 	if flags[2] is set
40 	u32 	height 	if flags[2] is set
44 	u32 	depth 	if flags[2] is set
"""

type
  TMultiboot_header = object
    magic:          uint32
    flags:          uint32
    checksum:       uint32
    headerAddress:  uint32
    loadAddress:    uint32
    loadEndAddress: uint32
    bssEndAddress:  uint32
    entryAddress:   uint32
    modeType:       uint32
    width:          uint32
    height:         uint32
    depth:          uint32

  PMultiboot_header = ptr TMultiboot_header

proc kernel_early() {.exportc.} =
  #Things we need to happen before everything else.
  gdtInstall()
  idtInstall()
  isrsInstall()
  irqInstall()

  #Don't do anything serious until all tables are initialized.
  terminalInitialize()
  terminalWrite("Initialized the terminal...\n")

  #Malloc and free
  allocInstall()
  terminalWrite("Allocation systems initialized...\n")

  #Let's enable paging
  initPaging()
  terminalWrite("Paging initialized...\n")

  #Some handlers..
  keyboardInstall()
  timerInstall()
  terminalWrite("Default handlers installed...\n")

  #Once we're done, we can safely enable hardware maskable interrupts
  {.emit: """
  __asm__ __volatile__ ("sti");
  """}

proc kernel_main(pmbh: PMultiboot_header) {.exportc noReturn.} =
  terminalWrite("Hello, world!\n")
  terminalSetColor(makeVGAAttribute(LightGreen, Green))
  terminalWrite("Testing colors...\n")

  terminalSetColor(makeVGAAttribute(Green, Black))
  terminalWrite("Testing decimal writing with 8675309: ")
  terminalWriteDecimal(8675309)
  terminalWrite("\n")

  terminalWrite("Testing hex writing with 0xDEADBEEF: ")
  terminalWriteHex(cast[uint](0xDEADBEEF))
  terminalWrite("\n")

  #Test the use of timer's wait function
  terminalSetColor(makeVGAAttribute(Red, Black))
  terminalWrite("WARNING: Escape causes debug interrupt!!!!\n")
  terminalSetColor(makeVGAAttribute(Green, Black))

  terminalWrite("\nTesting mallocs...\n")

  var xp: ptr uint32 = cast[ptr uint32](kmalloc(cast[uint32](sizeof(uint32))))
  xp[] = 777
  var xpAddr: uint32 = cast[uint32](xp)

  when false:
    terminalWrite("Got block at: ")
    terminalWriteHex(cast[uint32](xp))
    terminalWrite(". Setting the value to: ")
    terminalWriteDecimal(xp[])
    terminalWrite("\n")
  when false:
    for i in 0..3:
      var xp: ptr uint32 = cast[ptr uint32](kmalloc(cast[uint32](sizeof(uint32))))
      xp[] = 777
      when false:
        terminalWrite("Got block at: ")
        terminalWriteHex(cast[uint32](xp))
        terminalWrite(". Setting the value to: ")
        terminalWriteDecimal(xp[])
        terminalWrite("\n")

  #var yp: ptr uint32 = cast[ptr uint32](kmalloc(cast[uint32](sizeof(uint32))))
  #yp[] = 777
  #kfree(cast[uint32](yp))

  terminalWrite("Freeing first malloc! We should now get its address for this malloc\n")
  kfree(cast[uint32](xp))
  xp = cast[ptr uint32](kmalloc(cast[uint32](sizeof(uint32))))
  xp[] = 777


  #xp = cast[ptr uint32](kmalloc(cast[uint32](sizeof(uint32))))
  var op = cast[ptr uint32](kmalloc(cast[uint32](sizeof(uint32))))
  var tp = cast[ptr uint32](kmalloc(cast[uint32](sizeof(uint32))))
  var yp = cast[ptr uint32](kmalloc(cast[uint32](sizeof(uint32))))
  var zp = cast[ptr uint32](kmalloc(cast[uint32](sizeof(uint32))))

  kfree(cast[uint32](xp))

  terminalWrite("Malloc and Free tests: ")

  if xpAddr == cast[uint32](xp):
    terminalWrite("SUCCESS!\n")
  else:
    terminalWrite("FAILURE!\n")
    while true:
      discard

  terminalWrite("Testing merges on free...\n")
  kfree(cast[uint32](op))
  kfree(cast[uint32](tp))
  kfree(cast[uint32](yp))
  kfree(cast[uint32](zp))


  terminalWrite("Testing math...\n")

  terminalWrite("Testing log2(1) should be 0: ")
  #terminalWriteDecimal(log2(1))
  if log2(1) == 0:
    terminalWrite("SUCCESS!\n")
  else:
    terminalWrite("FAILURE!\n")

  terminalWrite("Testing 2^0 should be 1: ")
  if pow(2, 0) == 1:
    terminalWrite("SUCCESS!\n")
  else:
    terminalWrite("FAILURE!\n")

  terminalWrite("Testing 0^1 should be 0: ")
  if pow(0, 1) == 0:
    terminalWrite("SUCCESS!\n")
  else:
    terminalWrite("FAILURE!\n")

  terminalSlowWrite("Well actually...\n", 4)
  #terminalWrite("Testing 0^0 should fault: ")
  #terminalWriteDecimal(pow(0, 0))
  #terminalWrite("\n")

  while true:
    discard
