$NetBSD: patch-.._wmgeneral_list.h,v 1.1 2013/11/07 00:49:46 joerg Exp $

--- ../wmgeneral/list.h.orig	2013-11-07 00:24:26.000000000 +0000
+++ ../wmgeneral/list.h
@@ -29,11 +29,7 @@ Boston, MA 02111-1307, USA.  */
 #ifndef __LIST_H_
 #define __LIST_H_
 
-#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
-# define INLINE inline
-#else
-# define INLINE
-#endif
+#define INLINE
 
 typedef struct LinkedList {
   void *head;
