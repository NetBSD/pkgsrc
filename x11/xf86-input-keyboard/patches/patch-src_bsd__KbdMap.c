$NetBSD: patch-src_bsd__KbdMap.c,v 1.2 2020/09/19 13:52:14 taca Exp $

PR191459: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=191459
Fix a segmentation fault due to the use of Unicode codepoints in vt(4) which is
the default console driver from FreeBSD 11.

xsrc/54784: Cannot input some keys in JP keyboard on Xorg server when
specify wskbd Protocol.

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
@@ -581,20 +583,20 @@ static CARD8 wsXtMap[] = {
 	/* 109 */ KEY_NOTUSED,
 	/* 110 */ KEY_NOTUSED,
 	/* 111 */ KEY_NOTUSED,
-	/* 112 */ KEY_NOTUSED,
+	/* 112 */ KEY_HKTG,
 	/* 113 */ KEY_NOTUSED,
 	/* 114 */ KEY_NOTUSED,
-	/* 115 */ KEY_NOTUSED,
+	/* 115 */ KEY_BSlash2,
 	/* 116 */ KEY_NOTUSED,
 	/* 117 */ KEY_NOTUSED,
 	/* 118 */ KEY_NOTUSED,
 	/* 119 */ KEY_NOTUSED,
 	/* 120 */ KEY_NOTUSED,
-	/* 121 */ KEY_NOTUSED,
+	/* 121 */ KEY_XFER,
 	/* 122 */ KEY_NOTUSED,
-	/* 123 */ KEY_NOTUSED,
+	/* 123 */ KEY_NFER,
 	/* 124 */ KEY_NOTUSED,
-	/* 125 */ KEY_NOTUSED,
+	/* 125 */ KEY_Yen,
 	/* 126 */ KEY_NOTUSED,
 	/* 127 */ KEY_Pause,
 	/* 128 */ KEY_NOTUSED,
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
