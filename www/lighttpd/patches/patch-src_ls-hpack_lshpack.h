$NetBSD: patch-src_ls-hpack_lshpack.h,v 1.1 2024/02/21 21:32:13 schmonz Exp $

The compat file isn't present; unconditionally include.

--- src/ls-hpack/lshpack.h.orig	2024-02-21 21:28:48.938352829 +0000
+++ src/ls-hpack/lshpack.h
@@ -219,15 +219,7 @@ lshpack_dec_set_max_capacity (struct lsh
  * These structures are not very complicated.
  */
 
-#ifdef __has_include
-#if __has_include(<sys/queue.h>)
 #include <sys/queue.h>
-#endif
-#endif
-
-#ifndef SIMPLEQ_FOREACH
-#include "../compat/sys/queue.h"
-#endif
 
 /* OpenBSD and older MacOSX might not define STAILQ,
  * but ls-hpack usage could use SIMPLEQ as alternative */
