$NetBSD: patch-src_bsd__KbdMap.c,v 1.1 2018/01/21 10:12:39 triaxx Exp $

PR191459: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=191459
Fix a segmentation fault due to the use of Unicode codepoints in vt(4) which is
the default console driver from FreeBSD 11.

--- src/bsd_KbdMap.c.orig	2015-08-07 03:16:08.000000000 +0000
+++ src/bsd_KbdMap.c
@@ -28,6 +28,7 @@
 #include "bsd_kbd.h"
 
 #if (defined(SYSCONS_SUPPORT) || defined(PCVT_SUPPORT)) && defined(GIO_KEYMAP)
+#if !(defined(__FreeBSD__) && __FreeBSD__ >= 11)
 #define KD_GET_ENTRY(i,n) \
   eascii_to_x[((keymap.key[i].spcl << (n+1)) & 0x100) + keymap.key[i].map[n]]
 
@@ -188,6 +189,7 @@ static KeySym eascii_to_x[512] = {
 	NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
 	NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol
 };
+#endif /* !(defined(__FreeBSD__) && __FreeBSD__ >= 11) */
 
 #ifdef SYSCONS_SUPPORT
 static
@@ -1261,6 +1263,7 @@ KbdGetMapping (InputInfoPtr pInfo, KeySy
   KeySym        *k;
   int           i;
 
+#if !(defined(__FreeBSD__) && __FreeBSD__ >= 11)
 #ifndef __bsdi__
   switch (pKbd->consType) {
 
@@ -1294,6 +1297,7 @@ KbdGetMapping (InputInfoPtr pInfo, KeySy
     
   } 
 #endif /* !bsdi */
+#endif /* !(defined(__FreeBSD__) && __FreeBSD__ >= 11) */
 
   /*
    * compute the modifier map
