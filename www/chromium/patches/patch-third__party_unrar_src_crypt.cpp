$NetBSD: patch-third__party_unrar_src_crypt.cpp,v 1.29 2026/10/13 13:16:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/unrar/src/crypt.cpp.orig	2026-10-06 00:06:58.000000000 +0000
+++ third_party/unrar/src/crypt.cpp
@@ -126,6 +126,8 @@ void GetRnd(byte *RndBuf,size_t BufSize)
     Success=CryptGenRandom(hProvider, (DWORD)BufSize, RndBuf) != FALSE;
     CryptReleaseContext(hProvider, 0);
   }
+#elif defined(__OpenBSD__)
+  arc4random_buf(RndBuf, BufSize);
 #elif defined(_UNIX)
   FILE *rndf = fopen("/dev/urandom", "r");
   if (rndf!=NULL)
