$NetBSD: patch-Source_JavaScriptCore_offlineasm_arm64.rb,v 1.1 2018/11/13 20:11:38 leot Exp $

Add support for FreeBSD and NetBSD.

From FreeBSD ports.

--- Source/JavaScriptCore/offlineasm/arm64.rb.orig	2018-10-27 21:20:55.000000000 +0000
+++ Source/JavaScriptCore/offlineasm/arm64.rb
@@ -938,7 +938,7 @@ class Instruction
             $asm.puts "ldr #{operands[1].arm64Operand(:ptr)}, [#{operands[1].arm64Operand(:ptr)}, #{operands[0].asmLabel}@GOTPAGEOFF]"
 
             # On Linux, use ELF GOT relocation specifiers.
-            $asm.putStr("#elif OS(LINUX)")
+            $asm.putStr("#elif OS(LINUX) || OS(FREEBSD) || OS(NETBSD)")
             $asm.puts "adrp #{operands[1].arm64Operand(:ptr)}, :got:#{operands[0].asmLabel}"
             $asm.puts "ldr #{operands[1].arm64Operand(:ptr)}, [#{operands[1].arm64Operand(:ptr)}, :got_lo12:#{operands[0].asmLabel}]"
 
