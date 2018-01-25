$NetBSD: patch-hw_xfree86_os-support_solaris_solaris-amd64.S,v 1.1 2018/01/25 15:06:10 jperkin Exp $

Make assembly work with clang.

--- hw/xfree86/os-support/solaris/solaris-amd64.S.orig	2017-12-20 20:32:33.000000000 +0000
+++ hw/xfree86/os-support/solaris/solaris-amd64.S
@@ -1,3 +1,4 @@
+#if 0
 / Copyright (c) 2005, Oracle and/or its affiliates. All rights reserved.
 / 
 / Permission is hereby granted, free of charge, to any person obtaining a
@@ -18,6 +19,7 @@
 / LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 / FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 / DEALINGS IN THE SOFTWARE.
+#endif
 
 #ifdef INLINE_ASM
 #define FUNCTION_START(f,n)	.inline f,n
@@ -32,36 +34,36 @@
 	FUNCTION_START(inb,4)
 	movq	%rdi, %rdx
 	xorq    %rax, %rax
-	inb	(%dx)
+	inb	%dx
 	FUNCTION_END(inb)
 
 	FUNCTION_START(inw,4)
 	movq	%rdi, %rdx
 	xorq    %rax, %rax
-	inw	(%dx)
+	inw	%dx
 	FUNCTION_END(inw)
 
 	FUNCTION_START(inl,4)
 	movq	%rdi, %rdx
 	xorq    %rax, %rax
-	inl	(%dx)
+	inl	%dx
 	FUNCTION_END(inl)
 
 	FUNCTION_START(outb,8)
 	movq	%rdi, %rdx
 	movq    %rsi, %rax
-	outb	(%dx)
+	outb	%dx
 	FUNCTION_END(outb)
 
 	FUNCTION_START(outw,8)
 	movq	%rdi, %rdx
 	movq    %rsi, %rax
-	outw	(%dx)
+	outw	%dx
 	FUNCTION_END(outw)
 
 	FUNCTION_START(outl,8)
 	movq	%rdi, %rdx
 	movq    %rsi, %rax
-	outl	(%dx)
+	outl	%dx
 	FUNCTION_END(outl)
 
