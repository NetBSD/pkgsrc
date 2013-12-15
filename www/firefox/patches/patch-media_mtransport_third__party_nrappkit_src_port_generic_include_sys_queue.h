$NetBSD: patch-media_mtransport_third__party_nrappkit_src_port_generic_include_sys_queue.h,v 1.3 2013/12/15 13:54:37 ryoon Exp $

--- media/mtransport/third_party/nrappkit/src/port/generic/include/sys/queue.h.orig	2013-12-05 16:07:48.000000000 +0000
+++ media/mtransport/third_party/nrappkit/src/port/generic/include/sys/queue.h
@@ -30,12 +30,15 @@
  * $FreeBSD: src/sys/sys/queue.h,v 1.58 2004/04/07 04:19:49 imp Exp $
  */
 
-#ifndef _SYS_QUEUE_H_
+#if (defined(BSD) && !defined(__OpenBSD__)) || defined(DARWIN)
+#include_next <sys/queue.h>
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
@@ -43,8 +46,6 @@
              (var) && ((tvar) = STAILQ_NEXT((var), field), 1);           \
              (var) = (tvar))
 
-// #define __offsetof(type, field) ((size_t)(&((type *)0)->field))
-
 /*
  * This file defines four types of data structures: singly-linked lists,
  * singly-linked tail queues, lists and tail queues.
@@ -285,7 +286,7 @@ struct {								\
 	(STAILQ_EMPTY((head)) ?						\
 		NULL :							\
 	        ((struct type *)					\
-		((char *)((head)->stqh_last) - __offsetof(struct type, field))))
+		((char *)((head)->stqh_last) - offsetof(struct type, field))))
 
 #define	STAILQ_NEXT(elm, field)	((elm)->field.stqe_next)
 
