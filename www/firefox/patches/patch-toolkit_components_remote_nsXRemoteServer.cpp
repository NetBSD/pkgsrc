$NetBSD: patch-toolkit_components_remote_nsXRemoteServer.cpp,v 1.1 2026/09/01 15:55:09 ryoon Exp $

* Fix error, Success is not defined,

--- toolkit/components/remote/nsXRemoteServer.cpp.orig	2026-09-01 13:28:58.404435470 +0000
+++ toolkit/components/remote/nsXRemoteServer.cpp
@@ -110,7 +110,7 @@ bool nsXRemoteServer::HandleNewProperty(XID aWindowId,
 
     // Failed to get property off the window or
     // got a part only
-    if (result != Success || bytes_after != 0) {
+    if (result != X11Success || bytes_after != 0) {
       return false;
     }
 
