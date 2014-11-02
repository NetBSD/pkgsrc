$NetBSD: patch-mozilla_media_mtransport_third__party_nrappkit_src_port_generic_include_sys_queue.h,v 1.5 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/media/mtransport/third_party/nrappkit/src/port/generic/include/sys/queue.h.orig	2014-10-14 06:36:30.000000000 +0000
+++ mozilla/media/mtransport/third_party/nrappkit/src/port/generic/include/sys/queue.h
@@ -30,7 +30,13 @@
  * $FreeBSD: src/sys/sys/queue.h,v 1.58 2004/04/07 04:19:49 imp Exp $
  */
 
-#ifndef _SYS_QUEUE_H_
+#if (defined(BSD) && !defined(__OpenBSD__)) || defined(DARWIN)
+#include_next <sys/queue.h>
+# if defined(__DragonFly__)
+#define STAILQ_FOREACH_SAFE STAILQ_FOREACH_MUTABLE
+#define TAILQ_FOREACH_SAFE TAILQ_FOREACH_MUTABLE
+# endif
+#elif !defined(_SYS_QUEUE_H_)
 #define	_SYS_QUEUE_H_
 
 #include <stddef.h>
