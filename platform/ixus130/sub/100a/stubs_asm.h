    .text

#define DEF(n,a) \
    .globl n; n = a

#define NSTUB(name, addr)\
    .globl _##name ;\
    .weak _##name ;\
    _##name: ;\
	ldr  pc, = ## addr

#define NHSTUB(name, addr)\
    .globl _##name ;\
    _##name: ;\
	ldr  pc, = ## addr

#define STUB(addr)\
    .globl sub_ ## addr ;\
    sub_ ## addr: ;\
	ldr  pc, =0x ## addr

// Force finsig to ignore firmware version of a function - used when a custom
// version is provided that completely replaces firmware code.
//  e.g. IGNORE(MoveFocusLensToDistance) for a410 - alternate function supplied in focushack.c
#define IGNORE(name)

// Enable outputting constants from stubs_entry.S
#define DEF_CONST(n, m) \
    .globl n; n: ;\
    .long m

