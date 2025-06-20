$NetBSD: patch-src_session_Session.cpp,v 1.1 2025/06/20 02:35:50 markd Exp $

backport fix for CVE-2025-49091

--- src/session/Session.cpp.orig	2023-12-05 03:11:17.000000000 +0000
+++ src/session/Session.cpp
@@ -521,8 +521,10 @@ void Session::run()
     // if a program was specified via setProgram(), but it couldn't be found (but a fallback was), print a warning
     if (exec != checkProgram(_program)) {
         terminalWarning(i18n("Could not find '%1', starting '%2' instead.  Please check your profile settings.", _program, exec));
+	_arguments.clear(); // ignore args if program is invalid
     } else if (exec != checkProgram(exec)) {
         terminalWarning(i18n("Could not find '%1', starting '%2' instead.  Please check your profile settings.", exec, checkProgram(exec)));
+	_arguments.clear(); // ignore args if program is invalid
     }
 
     // if no arguments are specified, fall back to program name
