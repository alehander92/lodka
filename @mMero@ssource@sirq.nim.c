/* Generated by Nim Compiler v1.1.0 */
/*   (c) 2019 Andreas Rumpf */
/* The generated code is subject to the original license. */
#define NIM_INTBITS 32

#include "nimbase.h"
#include "setjmp.h"
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
typedef struct tyObject_registers__Mb0UOAid9c9c7v7uFPX18mcg tyObject_registers__Mb0UOAid9c9c7v7uFPX18mcg;
typedef struct Exception Exception;
typedef struct RootObj RootObj;
typedef struct TNimType TNimType;
typedef struct NimStrPayload NimStrPayload;
typedef struct AllocatorObj AllocatorObj;
typedef struct NimStringV2 NimStringV2;
typedef struct tySequence__uB9b75OUPRENsBAu4AnoePA tySequence__uB9b75OUPRENsBAu4AnoePA;
typedef struct tySequence__uB9b75OUPRENsBAu4AnoePA_Content tySequence__uB9b75OUPRENsBAu4AnoePA_Content;
typedef struct TSafePoint TSafePoint;
typedef struct tyObject_RefHeader__Gi7WQzlT1ZRToh9a2ueYb4A tyObject_RefHeader__Gi7WQzlT1ZRToh9a2ueYb4A;
typedef struct tyObject_StackTraceEntry__oLyohQ7O2XOvGnflOss8EA tyObject_StackTraceEntry__oLyohQ7O2XOvGnflOss8EA;
typedef struct {
N_NIMCALL_PTR(void, ClP_0) (tyObject_registers__Mb0UOAid9c9c7v7uFPX18mcg* regs, void* ClE_0);
void* ClE_0;
} tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ;
typedef tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ tyArray__go59cYo0lifoWWnigBty2Tg[16];
struct TNimType {
void* destructor;
NI size;
NCSTRING name;
};
struct RootObj {
TNimType* m_type;
};
struct NimStrPayload {
NI cap;
AllocatorObj* allocator;
NIM_CHAR data[SEQ_DECL_SIZE];
};
struct NimStringV2 {
NI len;
NimStrPayload* p;
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
struct tyObject_RefHeader__Gi7WQzlT1ZRToh9a2ueYb4A {
NI rc;
};
struct tyObject_registers__Mb0UOAid9c9c7v7uFPX18mcg {
NU32 gs;
NU32 fs;
NU32 es;
NU32 ds;
NU32 edi;
NU32 esi;
NU32 ebp;
NU32 esp;
NU32 ebx;
NU32 edx;
NU32 ecx;
NU32 eax;
NU32 int_no;
NU32 err_code;
NU32 eip;
NU32 cs;
NU32 eflags;
NU32 useresp;
NU32 ss;
};
typedef N_CLOSURE_PTR(void, TM__0xRZp3H9cHgeuOhm7vEmXCQ_5) (tyObject_registers__Mb0UOAid9c9c7v7uFPX18mcg* regs);
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

      extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

static N_INLINE(void, pushSafePoint)(TSafePoint* s);
static N_INLINE(void, popSafePoint)(void);
N_NIMCALL(void, reraiseException)(void);
N_NIMCALL(void, installHandler)(NI irq, tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ handler);
N_NIMCALL(void, irqInstall)(void);
N_LIB_PRIVATE N_NIMCALL(void, uninstallHandler__MHC2F9cdxbQ3CNvOoqNQsoQ)(NI irq);
N_LIB_PRIVATE N_NIMCALL(void, eqsink___BCUz6kQ3JH73RuZW9cAy8iw)(tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ* dest, tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ src);
static N_INLINE(void, nimDecWeakRef)(void* p);
N_LIB_PRIVATE N_NIMCALL(void, irqRemap__L2csWl1nQ3kCSSiMCwVByw)(void);
N_LIB_PRIVATE N_NIMCALL(void, outb__WHsX9cRAb9ansZ7pOaHMylNw)(NU16 port, NU8 value);
N_LIB_PRIVATE N_NIMCALL(void, idtSetGate__uB9aAbzjB9bRgxmfLMWFiDxw)(NU8 num, NU32 base, NU16 sel, NU8 flags);
N_LIB_PRIVATE N_NIMCALL(NU32, getIrq__nj7VDsgSqKXMeJByIbMM9cQ)(NI i);
N_NIMCALL(void, irq_handler)(tyObject_registers__Mb0UOAid9c9c7v7uFPX18mcg* regs);
N_LIB_PRIVATE N_NIMCALL(void, eq___BCUz6kQ3JH73RuZW9cAy8iw_2)(tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ* dest, tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ src);
static N_INLINE(void, nimIncRef)(void* p);
N_LIB_PRIVATE N_NIMCALL(void, eqdestroy___wiZEASkr9bT3U9bPF8brGOJQ)(tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ* dest);
tyArray__go59cYo0lifoWWnigBty2Tg irq_routines__YajyNUbwz3nSWLLa5toz3g;
static NIM_CONST tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ TM__0xRZp3H9cHgeuOhm7vEmXCQ_3 = {NIM_NIL,NIM_NIL};
static N_INLINE(void, pushSafePoint)(TSafePoint* s) {}
static N_INLINE(void, popSafePoint)(void) {}
N_NIMCALL(void, installHandler)(NI irq, tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ handler) {	  irq_routines__YajyNUbwz3nSWLLa5toz3g[irq] = handler;
  
}
static N_INLINE(void, nimDecWeakRef)(void* p) {	(*((tyObject_RefHeader__Gi7WQzlT1ZRToh9a2ueYb4A*) ((NI)((NU32)(((NI) (ptrdiff_t) (p))) - (NU32)(((NI) 4)))))).rc -= ((NI) 1);
}
N_LIB_PRIVATE N_NIMCALL(void, eqsink___BCUz6kQ3JH73RuZW9cAy8iw)(tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ* dest, tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ src) {	{
		if (!(*dest).ClE_0) goto LA3_;
		nimDecWeakRef((*dest).ClE_0);
	}
	LA3_: ;
	(*dest).ClE_0 = src.ClE_0;
	(*dest).ClP_0 = src.ClP_0;
}
N_LIB_PRIVATE N_NIMCALL(void, uninstallHandler__MHC2F9cdxbQ3CNvOoqNQsoQ)(NI irq) {	eqsink___BCUz6kQ3JH73RuZW9cAy8iw((&irq_routines__YajyNUbwz3nSWLLa5toz3g[(irq)- 0]), TM__0xRZp3H9cHgeuOhm7vEmXCQ_3);
}
N_LIB_PRIVATE N_NIMCALL(void, irqRemap__L2csWl1nQ3kCSSiMCwVByw)(void) {	outb__WHsX9cRAb9ansZ7pOaHMylNw(((NU16) 32), ((NU8) 17));
	outb__WHsX9cRAb9ansZ7pOaHMylNw(((NU16) 160), ((NU8) 17));
	outb__WHsX9cRAb9ansZ7pOaHMylNw(((NU16) 33), ((NU8) 32));
	outb__WHsX9cRAb9ansZ7pOaHMylNw(((NU16) 161), ((NU8) 40));
	outb__WHsX9cRAb9ansZ7pOaHMylNw(((NU16) 33), ((NU8) 4));
	outb__WHsX9cRAb9ansZ7pOaHMylNw(((NU16) 161), ((NU8) 2));
	outb__WHsX9cRAb9ansZ7pOaHMylNw(((NU16) 33), ((NU8) 1));
	outb__WHsX9cRAb9ansZ7pOaHMylNw(((NU16) 161), ((NU8) 1));
	outb__WHsX9cRAb9ansZ7pOaHMylNw(((NU16) 33), ((NU8) 0));
	outb__WHsX9cRAb9ansZ7pOaHMylNw(((NU16) 161), ((NU8) 0));
}
N_LIB_PRIVATE N_NIMCALL(NU32, getIrq__nj7VDsgSqKXMeJByIbMM9cQ)(NI i) {	NU32 result;
	result = (NU32)0;
	  switch(i) {
  case 0:
    result = irq0;
    break;
  case 1:
    result = irq1;
    break;
  case 2:
    result = irq2;
    break;
  case 3:
    result = irq3;
    break;
  case 4:
    result = irq4;
    break;
  case 5:
    result = irq5;
    break;
  case 6:
    result = irq6;
    break;
  case 7:
    result = irq7;
    break;
  case 8:
    result = irq8;
    break;
  case 9:
    result = irq9;
    break;
  case 10:
    result = irq10;
    break;
  case 11:
    result = irq11;
    break;
  case 12:
    result = irq12;
    break;
  case 13:
    result = irq13;
    break;
  case 14:
    result = irq14;
    break;
  case 15:
    result = irq15;
    break;
  }
  
	return result;
}
N_NIMCALL(void, irqInstall)(void) {	{
		NI i;
		NI res;
		i = (NI)0;
		res = ((NI) 0);
		{
			while (1) {
				if (!(res <= ((NI) 15))) goto LA3;
				i = res;
				uninstallHandler__MHC2F9cdxbQ3CNvOoqNQsoQ(i);
				res += ((NI) 1);
			} LA3: ;
		}
	}
	irqRemap__L2csWl1nQ3kCSSiMCwVByw();
	{
		NI i_2;
		NI res_2;
		i_2 = (NI)0;
		res_2 = ((NI) 0);
		{
			while (1) {
				NU32 T7_;
				if (!(res_2 <= ((NI) 15))) goto LA6;
				i_2 = res_2;
				T7_ = (NU32)0;
				T7_ = getIrq__nj7VDsgSqKXMeJByIbMM9cQ(i_2);
				idtSetGate__uB9aAbzjB9bRgxmfLMWFiDxw(((NU8) ((NI)(((NI) 32) + i_2))), T7_, ((NU16) (((NI) 8))), ((NU8) (((NI) 142))));
				res_2 += ((NI) 1);
			} LA6: ;
		}
	}
}
static N_INLINE(void, nimIncRef)(void* p) {	(*((tyObject_RefHeader__Gi7WQzlT1ZRToh9a2ueYb4A*) ((NI)((NU32)(((NI) (ptrdiff_t) (p))) - (NU32)(((NI) 4)))))).rc += ((NI) 1);
}
N_LIB_PRIVATE N_NIMCALL(void, eq___BCUz6kQ3JH73RuZW9cAy8iw_2)(tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ* dest, tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ src) {	{
		if (!src.ClE_0) goto LA3_;
		nimIncRef(src.ClE_0);
	}
	LA3_: ;
	{
		if (!(*dest).ClE_0) goto LA7_;
		nimDecWeakRef((*dest).ClE_0);
	}
	LA7_: ;
	(*dest).ClE_0 = src.ClE_0;
	(*dest).ClP_0 = src.ClP_0;
}
N_LIB_PRIVATE N_NIMCALL(void, eqdestroy___wiZEASkr9bT3U9bPF8brGOJQ)(tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ* dest) {	{
		if (!(*dest).ClE_0) goto LA3_;
		nimDecWeakRef((*dest).ClE_0);
	}
	LA3_: ;
}
N_NIMCALL(void, irq_handler)(tyObject_registers__Mb0UOAid9c9c7v7uFPX18mcg* regs) {	tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ handler;
	TSafePoint TM__0xRZp3H9cHgeuOhm7vEmXCQ_4;
	pushSafePoint(&TM__0xRZp3H9cHgeuOhm7vEmXCQ_4);
	TM__0xRZp3H9cHgeuOhm7vEmXCQ_4.status = setjmp(TM__0xRZp3H9cHgeuOhm7vEmXCQ_4.context);
	if (TM__0xRZp3H9cHgeuOhm7vEmXCQ_4.status == 0) {
		NU32 irqIndex;
		irqIndex = (NU32)((NU32)((*regs).int_no) - (NU32)(((NU32) 32)));
		eq___BCUz6kQ3JH73RuZW9cAy8iw_2((&handler), irq_routines__YajyNUbwz3nSWLLa5toz3g[(irqIndex)- 0]);
		{
			if (!!((handler.ClP_0 == 0))) goto LA4_;
			handler.ClE_0? handler.ClP_0(regs, handler.ClE_0):((TM__0xRZp3H9cHgeuOhm7vEmXCQ_5)(handler.ClP_0))(regs);
		}
		LA4_: ;
		{
			if (!((NU32)(((NU32) (((NI) 40)))) <= (NU32)((NU32)((NU32)(irqIndex) + (NU32)(((NU32) 32)))))) goto LA8_;
			outb__WHsX9cRAb9ansZ7pOaHMylNw(((NU16) 160), ((NU8) 32));
		}
		LA8_: ;
		outb__WHsX9cRAb9ansZ7pOaHMylNw(((NU16) 32), ((NU8) 32));
		popSafePoint();
	}
	else {
		popSafePoint();
	}
	{
		eqdestroy___wiZEASkr9bT3U9bPF8brGOJQ((&handler));
	}
	if (TM__0xRZp3H9cHgeuOhm7vEmXCQ_4.status != 0) reraiseException();
}
N_LIB_PRIVATE N_NIMCALL(void, eqdestroy___s7Xz6U8AnHt9bxaO3CZFs2w)(tyProc__1aExiFCFu1i6s9aK9bwfoA9bQ* dest) {	NI colontmp_;
	colontmp_ = ((NI) 0);
	{
		while (1) {
			if (!(colontmp_ < ((NI) 16))) goto LA2;
			{
				if (!dest[(colontmp_)- 0].ClE_0) goto LA5_;
				nimDecWeakRef(dest[(colontmp_)- 0].ClE_0);
			}
			LA5_: ;
			colontmp_ += ((NI) 1);
		} LA2: ;
	}
}
N_LIB_PRIVATE N_NIMCALL(void, unknown_irqInit000)(void) {
{
	TSafePoint TM__0xRZp3H9cHgeuOhm7vEmXCQ_2;
	pushSafePoint(&TM__0xRZp3H9cHgeuOhm7vEmXCQ_2);
	TM__0xRZp3H9cHgeuOhm7vEmXCQ_2.status = setjmp(TM__0xRZp3H9cHgeuOhm7vEmXCQ_2.context);
	if (TM__0xRZp3H9cHgeuOhm7vEmXCQ_2.status == 0) {
		popSafePoint();
	}
	else {
		popSafePoint();
	}
	{
	}
	if (TM__0xRZp3H9cHgeuOhm7vEmXCQ_2.status != 0) reraiseException();
}
}
