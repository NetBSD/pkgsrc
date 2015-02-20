$NetBSD: patch-wxc_src_extra.cpp,v 1.1 2015/02/20 23:39:31 joerg Exp $

--- wxc/src/extra.cpp.orig	2015-02-20 22:48:26.000000000 +0000
+++ wxc/src/extra.cpp
@@ -221,7 +221,7 @@ void wxInputSink::Start()
 
 int wxInputSink::GetId()
 {
-  return (int)m_input;
+  return (int)(intptr_t)m_input;
 }
 
 wxThread::ExitCode wxInputSink::Entry()
@@ -2256,47 +2256,47 @@ EWXWEXPORT(void*,wxLog_GetTimestamp)(voi
 
 EWXWEXPORT(void,LogError)(void* _msg)
 {
-        wxLogError((char*)_msg);
+        wxLogError("%s", (char*)_msg);
 }
 
 EWXWEXPORT(void,LogFatalError)(void* _msg)
 {
-        wxLogFatalError((char*)_msg);
+        wxLogFatalError("%s", (char*)_msg);
 }
 
 EWXWEXPORT(void,LogWarning)(void* _msg)
 {
-        wxLogWarning((char*)_msg);
+        wxLogWarning("%s", (char*)_msg);
 }
 
 EWXWEXPORT(void,LogMessage)(void* _msg)
 {
-        wxLogMessage((char*)_msg);
+        wxLogMessage("%s", (char*)_msg);
 }
 
 EWXWEXPORT(void,LogVerbose)(void* _msg)
 {
-        wxLogVerbose((char*)_msg);
+        wxLogVerbose("%s", (char*)_msg);
 }
 
 EWXWEXPORT(void,LogStatus)(void* _msg)
 {
-        wxLogStatus((char*)_msg);
+        wxLogStatus("%s", (char*)_msg);
 }
 
 EWXWEXPORT(void,LogSysError)(void* _msg)
 {
-        wxLogSysError((char*)_msg);
+        wxLogSysError("%s", (char*)_msg);
 }
 
 EWXWEXPORT(void,LogDebug)(void* _msg)
 {
-        wxLogDebug((char*)_msg);
+        wxLogDebug("%s", (char*)_msg);
 }
 
 EWXWEXPORT(void,LogTrace)(void* mask, void* _msg)
 {
-        wxLogTrace((char*) mask, (char*)_msg);
+        wxLogTrace("%s", (char*) mask, (char*)_msg);
 }
 
 /*-----------------------------------------------------------------------------
