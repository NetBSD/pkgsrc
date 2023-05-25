$NetBSD: patch-include_X11_Intrinsic.h,v 1.1 2023/05/25 11:53:09 jperkin Exp $

Do not use _Static_assert in C++ code.

--- include/X11/Intrinsic.h.orig	2023-04-09 20:48:48.000000000 +0000
+++ include/X11/Intrinsic.h
@@ -174,7 +174,7 @@ typedef unsigned short	Dimension;  /* Si
 typedef short		Position;   /* Offset from 0 coordinate		*/
 
 typedef void*		XtPointer;
-#if __STDC_VERSION__ >= 201112L
+#if __STDC_VERSION__ >= 201112L && !defined(__cplusplus)
 _Static_assert(sizeof(XtArgVal) >= sizeof(XtPointer), "XtArgVal too small");
 _Static_assert(sizeof(XtArgVal) >= sizeof(long), "XtArgVal too small");
 #endif
