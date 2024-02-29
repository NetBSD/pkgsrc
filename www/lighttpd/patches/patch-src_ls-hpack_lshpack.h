$NetBSD: patch-src_ls-hpack_lshpack.h,v 1.2 2024/02/29 18:42:29 schmonz Exp $

Apply upstream (106c4b147b) macOS sys/queue.h portability patch.

--- src/ls-hpack/lshpack.h.orig	2024-02-20 04:42:50.000000000 +0000
+++ src/ls-hpack/lshpack.h
@@ -225,6 +225,8 @@ lshpack_dec_set_max_capacity (struct lsh
 #endif
 #endif
 
+#ifndef STAILQ_FOREACH
+
 #ifndef SIMPLEQ_FOREACH
 #include "../compat/sys/queue.h"
 #endif
@@ -243,6 +245,8 @@ lshpack_dec_set_max_capacity (struct lsh
 #define STAILQ_FOREACH          SIMPLEQ_FOREACH
 #endif
 
+#endif
+
 #if defined(STAILQ_FIRST) && defined(STAILQ_NEXT) && !defined(STAILQ_FOREACH)
 #define STAILQ_FOREACH(var, head, field)                                \
         for((var) = STAILQ_FIRST((head));                               \
