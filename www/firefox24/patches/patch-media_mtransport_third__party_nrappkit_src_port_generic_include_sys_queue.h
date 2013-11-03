$NetBSD: patch-media_mtransport_third__party_nrappkit_src_port_generic_include_sys_queue.h,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- media/mtransport/third_party/nrappkit/src/port/generic/include/sys/queue.h.orig	2013-05-11 19:19:43.000000000 +0000
+++ media/mtransport/third_party/nrappkit/src/port/generic/include/sys/queue.h
@@ -33,7 +33,7 @@
 #ifndef _SYS_QUEUE_H_
 #define	_SYS_QUEUE_H_
 
-#ifndef DARWIN
+#if !defined(__FreeBSD__) && !defined(DARWIN)
 #include <stddef.h>
 #define __offsetof offsetof
 #endif
