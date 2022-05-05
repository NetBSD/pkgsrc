$NetBSD: patch-xpcom_reflect_xptcall_xptcstubsdecl.inc,v 1.2 2022/05/05 14:07:39 nia Exp $

Bring NetBSD in line with other BSDs. 
Not sure abut the impact, but there is no reason to single it out

--- xpcom/reflect/xptcall/xptcstubsdecl.inc.orig	2022-02-03 04:20:33.000000000 +0000
+++ xpcom/reflect/xptcall/xptcstubsdecl.inc
@@ -8,7 +8,7 @@
 *  1 is AddRef
 *  2 is Release
 */
-#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__) && !defined(__FreeBSD__))
+#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__) && !defined(__FreeBSD__) || !defined(__NetBSD__))
 NS_IMETHOD Stub3();
 NS_IMETHOD Stub4();
 NS_IMETHOD Stub5();
