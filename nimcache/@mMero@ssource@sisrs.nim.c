/* Generated by Nim Compiler v1.1.0 */
/*   (c) 2019 Andreas Rumpf */
/* The generated code is subject to the original license. */
#define NIM_INTBITS 32

#include "nimbase.h"
#include <setjmp.h>
#undef LANGUAGE_C
#undef MIPSEB
#undef MIPSEL
#undef PPC
#undef R3000
#undef R4000
#undef i386
#undef linux
#undef mips
#undef near
#undef far
#undef powerpc
#undef unix
#define nimfr_(x, y)
#define nimln_(x, y)
typedef struct NimStrPayload NimStrPayload;
typedef struct AllocatorObj AllocatorObj;
typedef struct NimStringV2 NimStringV2;
typedef struct Exception Exception;
typedef struct RootObj RootObj;
typedef struct TNimType TNimType;
typedef struct tySequence__uB9b75OUPRENsBAu4AnoePA tySequence__uB9b75OUPRENsBAu4AnoePA;
typedef struct tySequence__uB9b75OUPRENsBAu4AnoePA_Content tySequence__uB9b75OUPRENsBAu4AnoePA_Content;
typedef struct TSafePoint TSafePoint;
typedef struct tyObject_StackTraceEntry__oLyohQ7O2XOvGnflOss8EA tyObject_StackTraceEntry__oLyohQ7O2XOvGnflOss8EA;
struct NimStrPayload {
NI cap;
AllocatorObj* allocator;
NIM_CHAR data[SEQ_DECL_SIZE];
};
struct NimStringV2 {
NI len;
NimStrPayload* p;
};
typedef NimStringV2 tyArray__c2QNJmc34bMEk131Zq7ttQ[32];
struct TNimType {
void* destructor;
NI size;
NCSTRING name;
};
struct RootObj {
TNimType* m_type;
};
struct tySequence__uB9b75OUPRENsBAu4AnoePA {
  NI len; tySequence__uB9b75OUPRENsBAu4AnoePA_Content* p;
};
struct Exception {
  RootObj Sup;
Exception* parent;
NCSTRING name;
NimStringV2 message;
tySequence__uB9b75OUPRENsBAu4AnoePA trace;
NU raiseId;
Exception* up;
};
typedef struct {
N_NIMCALL_PTR(NIM_BOOL, ClP_0) (Exception* e, void* ClE_0);
void* ClE_0;
} tyProc__NT9bSe2DDkjdtx7j9aov2Z6g;
struct TSafePoint {
TSafePoint* prev;
NI status;
jmp_buf context;
NIM_BOOL hasRaiseAction;
tyProc__NT9bSe2DDkjdtx7j9aov2Z6g raiseAction;
};
typedef N_NIMCALL_PTR(void*, tyProc__g4DU8Xso7TeLfKjjMA54hg) (AllocatorObj* a, NI size, NI alignment);
typedef N_NIMCALL_PTR(void, tyProc__f0fmYWZ9bBl5n2coKW0dYBQ) (AllocatorObj* a, void* p, NI size);
typedef N_NIMCALL_PTR(void*, tyProc__pc9bof8Viqlm9byLAeLaBy4g) (AllocatorObj* a, void* p, NI oldSize, NI newSize);
typedef N_NIMCALL_PTR(void, tyProc__up7108S0Kt9cUg781lCWRSQ) (AllocatorObj* a);
typedef NU8 tySet_tyEnum_AllocatorFlag__djJDT3jOEYT7cpwNwzEzRg;
struct AllocatorObj {
TNimType* m_type;
tyProc__g4DU8Xso7TeLfKjjMA54hg alloc;
tyProc__f0fmYWZ9bBl5n2coKW0dYBQ dealloc;
tyProc__pc9bof8Viqlm9byLAeLaBy4g realloc;
tyProc__up7108S0Kt9cUg781lCWRSQ deallocAll;
tySet_tyEnum_AllocatorFlag__djJDT3jOEYT7cpwNwzEzRg flags;
NCSTRING name;
NI allocCount;
NI deallocCount;
};
struct tyObject_StackTraceEntry__oLyohQ7O2XOvGnflOss8EA {
NCSTRING procname;
NI line;
NCSTRING filename;
};


#ifndef tySequence__uB9b75OUPRENsBAu4AnoePA_Content_PP
#define tySequence__uB9b75OUPRENsBAu4AnoePA_Content_PP
struct tySequence__uB9b75OUPRENsBAu4AnoePA_Content { NI cap;AllocatorObj* allocator;tyObject_StackTraceEntry__oLyohQ7O2XOvGnflOss8EA data[SEQ_DECL_SIZE];};
#endif

      static N_INLINE(void, pushSafePoint)(TSafePoint* s);
static N_INLINE(void, popSafePoint)(void);
N_NIMCALL(void, reraiseException)(void);
extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

N_NIMCALL(void, isrsInstall)(void);
N_LIB_PRIVATE N_NIMCALL(void, idtSetGate__uB9aAbzjB9bRgxmfLMWFiDxw)(NU8 num, NU32 base, NU16 sel, NU8 flags);
N_LIB_PRIVATE N_NIMCALL(NU32, getIsr__DpkY9c2DnZ2BXLrXpI9cWbvg)(NI i);
N_LIB_PRIVATE N_NIMCALL(void, eqsink___aBBXmHFBEivKqERloP6zmA)(NimStringV2* dest, NimStringV2 src);
N_LIB_PRIVATE N_NIMCALL(void, eqdestroy___dS1BF3Vxjg9aJMmmhVJKSpQ)(NimStringV2* dest);
tyArray__c2QNJmc34bMEk131Zq7ttQ exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw;
static const struct {
  NI cap; void* allocator; NIM_CHAR data[18+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_3 = { 18, NIM_NIL, "Division by zero!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_4 = {18, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_3};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[7+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_5 = { 7, NIM_NIL, "Debug!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_6 = {7, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_5};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[24+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_7 = { 24, NIM_NIL, "Non maskable interrupt!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_8 = {24, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_7};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[7+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_9 = { 7, NIM_NIL, "INT 3!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_10 = {7, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_9};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[6+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_11 = { 6, NIM_NIL, "INTO!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_12 = {6, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_11};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[15+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_13 = { 15, NIM_NIL, "Out of Bounds!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_14 = {15, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_13};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[12+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_15 = { 12, NIM_NIL, "Bad opcode!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_16 = {12, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_15};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[26+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_17 = { 26, NIM_NIL, "Co-processor unavailable!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_18 = {26, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_17};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[14+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_19 = { 14, NIM_NIL, "Double Fault!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_20 = {14, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_19};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[30+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_21 = { 30, NIM_NIL, "Co-processor segment overrun!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_22 = {30, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_21};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[9+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_23 = { 9, NIM_NIL, "Bad TSS!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_24 = {9, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_23};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[21+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_25 = { 21, NIM_NIL, "Segment not present!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_26 = {21, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_25};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[13+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_27 = { 13, NIM_NIL, "Stack fault!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_28 = {13, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_27};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[26+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_29 = { 26, NIM_NIL, "General Protection Fault!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_30 = {26, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_29};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[12+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_31 = { 12, NIM_NIL, "Page fault!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_32 = {12, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_31};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[10+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_33 = { 10, NIM_NIL, "Reserved!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_34 = {10, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_33};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[26+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_35 = { 26, NIM_NIL, "Floating point exception!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_36 = {26, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_35};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[17+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_37 = { 17, NIM_NIL, "Alignment Check!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_38 = {17, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_37};
static const struct {
  NI cap; void* allocator; NIM_CHAR data[15+1];
} TM__A9av19ak2XpYuH2KeE9b9awKsA_39 = { 15, NIM_NIL, "Machine Check!\000" };
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_40 = {15, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_39};
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_41 = {10, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_33};
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_42 = {10, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_33};
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_43 = {10, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_33};
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_44 = {10, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_33};
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_45 = {10, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_33};
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_46 = {10, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_33};
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_47 = {10, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_33};
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_48 = {10, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_33};
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_49 = {10, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_33};
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_50 = {10, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_33};
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_51 = {10, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_33};
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_52 = {10, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_33};
static const NimStringV2 TM__A9av19ak2XpYuH2KeE9b9awKsA_53 = {10, (NimStrPayload*)&TM__A9av19ak2XpYuH2KeE9b9awKsA_33};
static N_INLINE(void, pushSafePoint)(TSafePoint* s) {}
static N_INLINE(void, popSafePoint)(void) {}
N_LIB_PRIVATE N_NIMCALL(NU32, getIsr__DpkY9c2DnZ2BXLrXpI9cWbvg)(NI i) {	NU32 result;
	result = (NU32)0;
	  switch(i) {
  case 0:
    result = isr0;
    break;
  case 1:
    result = isr1;
    break;
  case 2:
    result = isr2;
    break;
  case 3:
    result = isr3;
    break;
  case 4:
    result = isr4;
    break;
  case 5:
    result = isr5;
    break;
  case 6:
    result = isr6;
    break;
  case 7:
    result = isr7;
    break;
  case 8:
    result = isr8;
    break;
  case 9:
    result = isr9;
    break;
  case 10:
    result = isr10;
    break;
  case 11:
    result = isr11;
    break;
  case 12:
    result = isr12;
    break;
  case 13:
    result = isr13;
    break;
  case 14:
    result = isr14;
    break;
  case 15:
    result = isr15;
    break;
  case 16:
    result = isr16;
    break;
  case 17:
    result = isr17;
    break;
  case 18:
    result = isr18;
    break;
  case 19:
    result = isr19;
    break;
  case 20:
    result = isr20;
    break;
  case 21:
    result = isr21;
    break;
  case 22:
    result = isr22;
    break;
  case 23:
    result = isr23;
    break;
  case 24:
    result = isr24;
    break;
  case 25:
    result = isr25;
    break;
  case 26:
    result = isr26;
    break;
  case 27:
    result = isr27;
    break;
  case 28:
    result = isr28;
    break;
  case 29:
    result = isr29;
    break;
  case 30:
    result = isr30;
    break;
  case 31:
    result = isr31;
  }
  
	return result;
}
N_NIMCALL(void, isrsInstall)(void) {	{
		NI i;
		NI res;
		i = (NI)0;
		res = ((NI) 0);
		{
			while (1) {
				NU32 T4_;
				if (!(res <= ((NI) 31))) goto LA3;
				i = res;
				T4_ = (NU32)0;
				T4_ = getIsr__DpkY9c2DnZ2BXLrXpI9cWbvg(i);
				idtSetGate__uB9aAbzjB9bRgxmfLMWFiDxw(((NU8) (i)), T4_, ((NU16) 8), ((NU8) 142));
				res += ((NI) 1);
			} LA3: ;
		}
	}
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 0))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_4);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 1))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_6);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 2))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_8);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 3))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_10);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 4))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_12);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 5))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_14);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 6))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_16);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 7))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_18);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 8))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_20);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 9))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_22);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 10))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_24);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 11))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_26);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 12))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_28);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 13))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_30);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 14))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_32);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 15))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_34);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 16))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_36);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 17))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_38);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 18))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_40);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 19))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_41);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 20))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_42);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 21))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_43);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 22))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_44);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 23))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_45);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 24))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_46);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 25))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_47);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 26))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_48);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 27))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_49);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 28))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_50);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 29))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_51);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 30))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_52);
	eqsink___aBBXmHFBEivKqERloP6zmA((&exceptionMessages__aEliYTX2OYxY9aYVbXJQtcw[(((NI) 31))- 0]), TM__A9av19ak2XpYuH2KeE9b9awKsA_53);
}
N_LIB_PRIVATE N_NIMCALL(void, eqdestroy___GF7fBXzeJgtHVCogYAjhKw)(NimStringV2* dest) {	NI colontmp_;
	colontmp_ = ((NI) 0);
	{
		while (1) {
			if (!(colontmp_ < ((NI) 32))) goto LA2;
			eqdestroy___dS1BF3Vxjg9aJMmmhVJKSpQ((&dest[(colontmp_)- 0]));
			colontmp_ += ((NI) 1);
		} LA2: ;
	}
}
N_LIB_PRIVATE N_NIMCALL(void, unknown_isrsInit000)(void) {
{
	TSafePoint TM__A9av19ak2XpYuH2KeE9b9awKsA_2;
	pushSafePoint(&TM__A9av19ak2XpYuH2KeE9b9awKsA_2);
	TM__A9av19ak2XpYuH2KeE9b9awKsA_2.status = setjmp(TM__A9av19ak2XpYuH2KeE9b9awKsA_2.context);
	if (TM__A9av19ak2XpYuH2KeE9b9awKsA_2.status == 0) {
		popSafePoint();
	}
	else {
		popSafePoint();
	}
	{
	}
	if (TM__A9av19ak2XpYuH2KeE9b9awKsA_2.status != 0) reraiseException();
}
}
