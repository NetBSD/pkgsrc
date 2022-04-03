$NetBSD: patch-js_src_jit_GenerateAtomicOperations.py,v 1.1 2022/04/03 00:22:30 ryoon Exp $

* Fix build under 32-bit architecture, for example NetBSD/i386.
  From: https://bugzilla.mozilla.org/show_bug.cgi?id=1756347

--- js/src/jit/GenerateAtomicOperations.py.orig	2022-03-03 09:53:14.696789711 +0000
+++ js/src/jit/GenerateAtomicOperations.py
@@ -10,6 +10,7 @@ import buildconfig
 
 is_64bit = "JS_64BIT" in buildconfig.defines
 cpu_arch = buildconfig.substs["CPU_ARCH"]
+is_gcc = buildconfig.substs["CC_TYPE"] == "gcc"
 
 
 def fmt_insn(s):
@@ -19,21 +20,21 @@ def fmt_insn(s):
 def gen_seqcst(fun_name):
     if cpu_arch in ("x86", "x86_64"):
         return r"""
-            inline void %(fun_name)s() {
+            INLINE_ATTR void %(fun_name)s() {
                 asm volatile ("mfence\n\t" ::: "memory");
             }""" % {
             "fun_name": fun_name,
         }
     if cpu_arch == "aarch64":
         return r"""
-            inline void %(fun_name)s() {
+            INLINE_ATTR void %(fun_name)s() {
                 asm volatile ("dmb ish\n\t" ::: "memory");
             }""" % {
             "fun_name": fun_name,
         }
     if cpu_arch == "arm":
         return r"""
-            inline void %(fun_name)s() {
+            INLINE_ATTR void %(fun_name)s() {
                 asm volatile ("dmb sy\n\t" ::: "memory");
             }""" % {
             "fun_name": fun_name,
@@ -63,7 +64,7 @@ def gen_load(fun_name, cpp_type, size, b
         if barrier:
             insns += fmt_insn("mfence")
         return """
-            inline %(cpp_type)s %(fun_name)s(const %(cpp_type)s* arg) {
+            INLINE_ATTR %(cpp_type)s %(fun_name)s(const %(cpp_type)s* arg) {
                 %(cpp_type)s res;
                 asm volatile (%(insns)s
                     : [res] "=r" (res)
@@ -91,7 +92,7 @@ def gen_load(fun_name, cpp_type, size, b
         if barrier:
             insns += fmt_insn("dmb ish")
         return """
-            inline %(cpp_type)s %(fun_name)s(const %(cpp_type)s* arg) {
+            INLINE_ATTR %(cpp_type)s %(fun_name)s(const %(cpp_type)s* arg) {
                 %(cpp_type)s res;
                 asm volatile (%(insns)s
                     : [res] "=r" (res)
@@ -117,7 +118,7 @@ def gen_load(fun_name, cpp_type, size, b
         if barrier:
             insns += fmt_insn("dmb sy")
         return """
-            inline %(cpp_type)s %(fun_name)s(const %(cpp_type)s* arg) {
+            INLINE_ATTR %(cpp_type)s %(fun_name)s(const %(cpp_type)s* arg) {
                 %(cpp_type)s res;
                 asm volatile (%(insns)s
                     : [res] "=r" (res)
@@ -154,7 +155,7 @@ def gen_store(fun_name, cpp_type, size, 
         if barrier:
             insns += fmt_insn("mfence")
         return """
-            inline void %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
+            INLINE_ATTR void %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
                 asm volatile (%(insns)s
                     :
                     : [addr] "r" (addr), [val] "r"(val)
@@ -180,7 +181,7 @@ def gen_store(fun_name, cpp_type, size, 
         if barrier:
             insns += fmt_insn("dmb ish")
         return """
-            inline void %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
+            INLINE_ATTR void %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
                 asm volatile (%(insns)s
                     :
                     : [addr] "r" (addr), [val] "r"(val)
@@ -204,7 +205,7 @@ def gen_store(fun_name, cpp_type, size, 
         if barrier:
             insns += fmt_insn("dmb sy")
         return """
-            inline void %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
+            INLINE_ATTR void %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
                 asm volatile (%(insns)s
                     :
                     : [addr] "r" (addr), [val] "r"(val)
@@ -235,7 +236,7 @@ def gen_exchange(fun_name, cpp_type, siz
             assert size == 64
             insns += fmt_insn("xchgq %[val], (%[addr])")
         return """
-            inline %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
+            INLINE_ATTR %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
                 asm volatile (%(insns)s
                     : [val] "+r" (val)
                     : [addr] "r" (addr)
@@ -266,7 +267,7 @@ def gen_exchange(fun_name, cpp_type, siz
         insns += fmt_insn("cbnz %w[scratch], 0b")
         insns += fmt_insn("dmb ish")
         return """
-            inline %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
+            INLINE_ATTR %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
                 %(cpp_type)s res;
                 uint32_t scratch;
                 asm volatile (%(insns)s
@@ -297,7 +298,7 @@ def gen_exchange(fun_name, cpp_type, siz
         insns += fmt_insn("beq 0b")
         insns += fmt_insn("dmb sy")
         return """
-            inline %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
+            INLINE_ATTR %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
                 %(cpp_type)s res;
                 uint32_t scratch;
                 asm volatile (%(insns)s
@@ -321,7 +322,7 @@ def gen_cmpxchg(fun_name, cpp_type, size
         # Use a +A constraint to load `oldval` into EDX:EAX as input/output.
         # `newval` is loaded into ECX:EBX.
         return r"""
-            inline %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr,
+            INLINE_ATTR %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr,
                                              %(cpp_type)s oldval,
                                              %(cpp_type)s newval) {
                 asm volatile ("lock; cmpxchg8b (%%[addr])\n\t"
@@ -337,7 +338,7 @@ def gen_cmpxchg(fun_name, cpp_type, size
         }
     if cpu_arch == "arm" and size == 64:
         return r"""
-            inline %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr,
+            INLINE_ATTR %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr,
                                              %(cpp_type)s oldval,
                                              %(cpp_type)s newval) {
                 uint32_t oldval0 = oldval & 0xffff'ffff;
@@ -380,7 +381,7 @@ def gen_cmpxchg(fun_name, cpp_type, size
             assert size == 64
             insns += fmt_insn("lock; cmpxchgq %[newval], (%[addr])")
         return """
-            inline %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr,
+            INLINE_ATTR %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr,
                                              %(cpp_type)s oldval,
                                              %(cpp_type)s newval) {
                 asm volatile (%(insns)s
@@ -425,7 +426,7 @@ def gen_cmpxchg(fun_name, cpp_type, size
         insns += fmt_insn("cbnz %w[scratch], 0b")
         insns += fmt_insn("1: dmb ish")
         return """
-            inline %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr,
+            INLINE_ATTR %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr,
                                              %(cpp_type)s oldval,
                                              %(cpp_type)s newval) {
                 %(cpp_type)s res, scratch;
@@ -466,7 +467,7 @@ def gen_cmpxchg(fun_name, cpp_type, size
         insns += fmt_insn("beq 0b")
         insns += fmt_insn("1: dmb sy")
         return """
-            inline %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr,
+            INLINE_ATTR %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr,
                                              %(cpp_type)s oldval,
                                              %(cpp_type)s newval) {
                 %(cpp_type)s res, scratch;
@@ -501,7 +502,7 @@ def gen_fetchop(fun_name, cpp_type, size
                 assert size == 64
                 insns += fmt_insn("lock; xaddq %[val], (%[addr])")
             return """
-                inline %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
+                INLINE_ATTR %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
                     asm volatile (%(insns)s
                         : [val] "+&r" (val)
                         : [addr] "r" (addr)
@@ -539,7 +540,7 @@ def gen_fetchop(fun_name, cpp_type, size
         insns = insns.replace("OP", op)
         insns += fmt_insn("jnz 0b")
         return """
-            inline %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
+            INLINE_ATTR %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
                 %(cpp_type)s res, scratch;
                 asm volatile (%(insns)s
                     : [res] "=&a" (res), [scratch] "=&r" (scratch)
@@ -581,7 +582,7 @@ def gen_fetchop(fun_name, cpp_type, size
         insns += fmt_insn("cbnz %w[scratch2], 0b")
         insns += fmt_insn("dmb ish")
         return """
-            inline %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
+            INLINE_ATTR %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
                 %(cpp_type)s res;
                 uintptr_t scratch1, scratch2;
                 asm volatile (%(insns)s
@@ -621,7 +622,7 @@ def gen_fetchop(fun_name, cpp_type, size
         insns += fmt_insn("beq 0b")
         insns += fmt_insn("dmb sy")
         return """
-            inline %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
+            INLINE_ATTR %(cpp_type)s %(fun_name)s(%(cpp_type)s* addr, %(cpp_type)s val) {
                 %(cpp_type)s res;
                 uintptr_t scratch1, scratch2;
                 asm volatile (%(insns)s
@@ -665,12 +666,12 @@ def gen_copy(fun_name, cpp_type, size, u
                 insns += fmt_insn("str %x[scratch], [%x[dst], OFFSET]")
         elif cpu_arch == "arm":
             if size == 1:
-                insns += fmt_insn("ldrb %[scratch], [%[src], OFFSET]")
-                insns += fmt_insn("strb %[scratch], [%[dst], OFFSET]")
+                insns += fmt_insn("ldrb %[scratch], [%[src], #OFFSET]")
+                insns += fmt_insn("strb %[scratch], [%[dst], #OFFSET]")
             else:
                 assert size == 4
-                insns += fmt_insn("ldr %[scratch], [%[src], OFFSET]")
-                insns += fmt_insn("str %[scratch], [%[dst], OFFSET]")
+                insns += fmt_insn("ldr %[scratch], [%[src], #OFFSET]")
+                insns += fmt_insn("str %[scratch], [%[dst], #OFFSET]")
         else:
             raise Exception("Unexpected arch")
         insns = insns.replace("OFFSET", str(offset * size))
@@ -681,7 +682,7 @@ def gen_copy(fun_name, cpp_type, size, u
             offset -= 1
 
     return """
-        inline void %(fun_name)s(uint8_t* dst, const uint8_t* src) {
+        INLINE_ATTR void %(fun_name)s(uint8_t* dst, const uint8_t* src) {
             %(cpp_type)s* dst_ = reinterpret_cast<%(cpp_type)s*>(dst);
             const %(cpp_type)s* src_ = reinterpret_cast<const %(cpp_type)s*>(src);
             %(cpp_type)s scratch;
@@ -853,6 +854,13 @@ def generate_atomics_header(c_out):
             "constexpr size_t JS_GENERATED_ATOMICS_WORDSIZE = " + str(wordsize) + ";\n"
         )
 
+        # Work around a GCC issue on 32-bit x86 by adding MOZ_NEVER_INLINE.
+        # See bug 1756347.
+        if is_gcc and cpu_arch == "x86":
+            contents = contents.replace("INLINE_ATTR", "MOZ_NEVER_INLINE inline")
+        else:
+            contents = contents.replace("INLINE_ATTR", "inline")
+
     c_out.write(
         HEADER_TEMPLATE
         % {
