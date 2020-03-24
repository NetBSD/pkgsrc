$NetBSD: patch-kjs_interpreter.cpp,v 1.2 2020/03/24 20:34:31 joerg Exp $

--- kjs/interpreter.cpp.orig	2017-11-05 01:51:22.000000000 +0000
+++ kjs/interpreter.cpp
@@ -64,6 +64,7 @@
 #include <math.h>
 #include <signal.h>
 #include <stdio.h>
+#include <cstdlib>
 #if defined(HAVE_UNISTD_H)
 #include <unistd.h>
 #endif
@@ -111,8 +112,8 @@ void TimeoutChecker::startTimeoutCheck(I
     s_executingInterpreter = interpreter;
 
     itimerval tv = {
-      { interpreter->m_timeoutTime / 1000, (interpreter->m_timeoutTime % 1000) * 1000 },
-      { interpreter->m_timeoutTime / 1000, (interpreter->m_timeoutTime % 1000) * 1000 }
+      { interpreter->m_timeoutTime / 1000, suseconds_t((interpreter->m_timeoutTime % 1000) * 1000) },
+      { interpreter->m_timeoutTime / 1000, suseconds_t((interpreter->m_timeoutTime % 1000) * 1000) }
     };
     setitimer(ITIMER_REAL, &tv, &m_oldtv);
 
