$NetBSD: patch-src_scripttools_debugging_qscriptdebuggerconsole.cpp,v 1.1 2013/08/29 13:00:41 joerg Exp $

--- src/scripttools/debugging/qscriptdebuggerconsole.cpp.orig	2013-07-12 12:05:08.000000000 +0000
+++ src/scripttools/debugging/qscriptdebuggerconsole.cpp
@@ -489,7 +489,7 @@ QScriptDebuggerConsoleCommandJob *QScrip
     d->input += QLatin1Char('\n');
     QScriptSyntaxCheckResult check = QScriptEngine::checkSyntax(d->input);
     if (check.state() == QScriptSyntaxCheckResult::Intermediate)
-        return false;
+        return 0;
     d->input.chop(1); // remove the last \n
     cmd = QString();
     cmd.append(d->commandPrefix);
