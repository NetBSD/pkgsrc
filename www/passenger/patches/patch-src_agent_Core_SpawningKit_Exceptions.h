$NetBSD: patch-src_agent_Core_SpawningKit_Exceptions.h,v 1.1 2019/01/06 09:52:50 markd Exp $

NetBSD "id" doesn't know about "-a" and linux "id" does same thing
with or without it so drop argument.

--- src/agent/Core/SpawningKit/Exceptions.h.orig	2013-10-27 00:00:00.000000000 +0000
+++ src/agent/Core/SpawningKit/Exceptions.h
@@ -754,7 +754,7 @@ private:
 	}
 
 	static string gatherUserInfo() {
-		const char *command[] = { "id", "-a", NULL };
+		const char *command[] = { "id", NULL };
 		try {
 			SubprocessInfo info;
 			SubprocessOutput output;
