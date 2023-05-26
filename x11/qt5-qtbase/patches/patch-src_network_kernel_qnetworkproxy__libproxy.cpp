$NetBSD: patch-src_network_kernel_qnetworkproxy__libproxy.cpp,v 1.1 2023/05/26 07:09:39 wiz Exp $

Adapt for libproxy header path change.

--- src/network/kernel/qnetworkproxy_libproxy.cpp.orig	2023-03-23 19:06:47.000000000 +0000
+++ src/network/kernel/qnetworkproxy_libproxy.cpp
@@ -49,7 +49,7 @@
 #include <QtCore/private/qeventdispatcher_unix_p.h>
 #include <QtCore/private/qthread_p.h>
 
-#include <proxy.h>
+#include <libproxy/proxy.h>
 #include <dlfcn.h>
 
 QT_BEGIN_NAMESPACE
