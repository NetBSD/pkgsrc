$NetBSD: patch-common_errno__to__string.cc,v 1.2 2022/07/11 18:25:18 schmonz Exp $

Add missing include.

--- common/errno_to_string.cc.orig	2019-12-19 14:19:58.476027186 +0000
+++ common/errno_to_string.cc
@@ -27,6 +27,7 @@
 #include "errno_to_string.h"
 
 // <cstring> doesn't give us strerror_r() with Sun C++ 5.9.
+#include <errno.h>
 #include <string.h>
 #if defined HAVE__SYS_ERRLIST_AND__SYS_NERR || \
     defined HAVE_SYS_ERRLIST_AND_SYS_NERR
