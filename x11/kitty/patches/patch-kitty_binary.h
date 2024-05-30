$NetBSD: patch-kitty_binary.h,v 1.1 2024/05/30 15:00:54 ktnb Exp $

Avoid symbol conflict on NetBSD.

--- kitty/binary.h.orig	2023-10-05 11:08:03.000000000 +0000
+++ kitty/binary.h
@@ -8,6 +8,7 @@
 
 #include <stdint.h>
 
+#ifndef __NetBSD__
 static inline uint16_t
 be16dec(const void *pp) {
     uint8_t const *p = (uint8_t const *)pp;
@@ -91,3 +92,4 @@ le64enc(void *pp, uint64_t u) {
     le32enc(p, (uint32_t)(u & 0xffffffffU));
     le32enc(p + 4, (uint32_t)(u >> 32));
 }
+#endif
