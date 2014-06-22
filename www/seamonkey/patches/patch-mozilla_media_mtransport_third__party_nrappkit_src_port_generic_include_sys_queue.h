$NetBSD: patch-mozilla_media_mtransport_third__party_nrappkit_src_port_generic_include_sys_queue.h,v 1.4 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/media/mtransport/third_party/nrappkit/src/port/generic/include/sys/queue.h.orig	2014-06-13 00:45:42.000000000 +0000
+++ mozilla/media/mtransport/third_party/nrappkit/src/port/generic/include/sys/queue.h
@@ -30,12 +30,19 @@
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
 
-#if !defined(__FreeBSD__) && !defined(DARWIN)
 #include <stddef.h>
-#define __offsetof offsetof
+
+#ifndef offsetof
+#define offsetof(type, field) ((size_t)(&((type *)0)->field))
 #endif
 
 #define STAILQ_FOREACH_SAFE(var, head, field, tvar)                     \
@@ -43,8 +50,6 @@
              (var) && ((tvar) = STAILQ_NEXT((var), field), 1);           \
              (var) = (tvar))
 
-// #define __offsetof(type, field) ((size_t)(&((type *)0)->field))
-
 /*
  * This file defines four types of data structures: singly-linked lists,
  * singly-linked tail queues, lists and tail queues.
@@ -285,7 +290,7 @@ struct {								\
 	(STAILQ_EMPTY((head)) ?						\
 		NULL :							\
 	        ((struct type *)					\
-		((char *)((head)->stqh_last) - __offsetof(struct type, field))))
+		((char *)((head)->stqh_last) - offsetof(struct type, field))))
 
 #define	STAILQ_NEXT(elm, field)	((elm)->field.stqe_next)
 
