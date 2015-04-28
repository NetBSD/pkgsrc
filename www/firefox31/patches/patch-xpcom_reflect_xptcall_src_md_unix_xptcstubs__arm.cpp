$NetBSD: patch-xpcom_reflect_xptcall_src_md_unix_xptcstubs__arm.cpp,v 1.1 2015/04/28 12:06:34 joerg Exp $

--- xpcom/reflect/xptcall/src/md/unix/xptcstubs_arm.cpp.orig	2015-04-25 16:42:42.000000000 +0000
+++ xpcom/reflect/xptcall/src/md/unix/xptcstubs_arm.cpp
@@ -130,24 +130,33 @@ __asm__ ("\n"
          ".text\n"
          ".align 2\n"
          "SharedStub:\n"
+#if defined(__ARM_EABI__) && !defined(__ARM_DWARF_EH__)
          ".fnstart\n"
+#endif
          CFI(".cfi_startproc\n")
          "stmfd	sp!, {r1, r2, r3}\n"
+#if defined(__ARM_EABI__) && !defined(__ARM_DWARF_EH__)
          ".save	{r1, r2, r3}\n"
+#endif
          CFI(".cfi_def_cfa_offset 12\n")
          CFI(".cfi_offset r3, -4\n")
          CFI(".cfi_offset r2, -8\n")
          CFI(".cfi_offset r1, -12\n")
          "mov	r2, sp\n"
          "str	lr, [sp, #-4]!\n"
+#if defined(__ARM_EABI__) && !defined(__ARM_DWARF_EH__)
          ".save	{lr}\n"
+#endif
          CFI(".cfi_def_cfa_offset 16\n")
          CFI(".cfi_offset lr, -16\n")
          "mov	r1, ip\n"
          "bl	_PrepareAndDispatch\n"
          "ldr	pc, [sp], #16\n"
          CFI(".cfi_endproc\n")
-         ".fnend");
+#if defined(__ARM_EABI__) && !defined(__ARM_DWARF_EH__)
+         ".fnend"
+#endif
+         );
 
 /*
  * Create sets of stubs to call the SharedStub.
