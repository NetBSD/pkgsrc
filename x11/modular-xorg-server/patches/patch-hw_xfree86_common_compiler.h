$NetBSD: patch-hw_xfree86_common_compiler.h,v 1.2 2015/04/25 11:47:03 tnn Exp $

--- hw/xfree86/common/compiler.h.orig	2015-01-17 23:42:52.000000000 +0000
+++ hw/xfree86/common/compiler.h
@@ -972,26 +972,26 @@ inl(unsigned PORT_SIZE port)
 static __inline__ void
 outb(unsigned short port, unsigned char val)
 {
-    __asm__ __volatile__("out%B0 (%1)"::"a"(val), "d"(port));
+    __asm__ __volatile__("outb %0, %1"::"a"(val), "d"(port));
 }
 
 static __inline__ void
 outw(unsigned short port, unsigned short val)
 {
-    __asm__ __volatile__("out%W0 (%1)"::"a"(val), "d"(port));
+    __asm__ __volatile__("outw %0, %1"::"a"(val), "d"(port));
 }
 
 static __inline__ void
 outl(unsigned short port, unsigned int val)
 {
-    __asm__ __volatile__("out%L0 (%1)"::"a"(val), "d"(port));
+    __asm__ __volatile__("outl %0, %1"::"a"(val), "d"(port));
 }
 
 static __inline__ unsigned int
 inb(unsigned short port)
 {
     unsigned char ret;
-    __asm__ __volatile__("in%B0 (%1)":"=a"(ret):"d"(port));
+    __asm__ __volatile__("inb %1, %0":"=a"(ret):"d"(port));
 
     return ret;
 }
@@ -1000,7 +1000,7 @@ static __inline__ unsigned int
 inw(unsigned short port)
 {
     unsigned short ret;
-    __asm__ __volatile__("in%W0 (%1)":"=a"(ret):"d"(port));
+    __asm__ __volatile__("inw %1, %0":"=a"(ret):"d"(port));
 
     return ret;
 }
@@ -1009,7 +1009,7 @@ static __inline__ unsigned int
 inl(unsigned short port)
 {
     unsigned int ret;
-    __asm__ __volatile__("in%L0 (%1)":"=a"(ret):"d"(port));
+    __asm__ __volatile__("inl %1, %0":"=a"(ret):"d"(port));
 
     return ret;
 }
