$NetBSD: patch-src_agent_Core_ApplicationPool_Group_ProcessListManagement.cpp,v 1.1 2020/03/27 20:51:23 joerg Exp $

--- src/agent/Core/ApplicationPool/Group/ProcessListManagement.cpp.orig	2020-03-27 14:52:59.290944767 +0000
+++ src/agent/Core/ApplicationPool/Group/ProcessListManagement.cpp
@@ -305,7 +305,7 @@ Group::detachedProcessesCheckerMain(Grou
 	while (true) {
 		assert(detachedProcessesCheckerActive);
 
-		if (getLifeStatus() == SHUT_DOWN || this_thread::interruption_requested()) {
+		if (getLifeStatus() == SHUT_DOWN || boost::this_thread::interruption_requested()) {
 			UPDATE_TRACE_POINT();
 			P_DEBUG("Stopping detached processes checker");
 			detachedProcessesCheckerActive = false;
