$NetBSD: patch-src_unix_dialup.cpp,v 1.1 2022/07/21 11:39:21 wiz Exp $

Add NetBSD support.
https://github.com/wxWidgets/wxWidgets/pull/22645

--- src/unix/dialup.cpp.orig	2022-07-06 14:19:50.000000000 +0000
+++ src/unix/dialup.cpp
@@ -795,6 +795,7 @@ wxDialUpManagerImpl::NetConnection wxDia
     // nothing to add to ping command
 #elif defined(__AIX__) || \
       defined (__BSD__) || \
+      defined (__NetBSD__) || \
       defined(__LINUX__) || \
       defined(__OSF__) || \
       defined(__SGI__) || \
