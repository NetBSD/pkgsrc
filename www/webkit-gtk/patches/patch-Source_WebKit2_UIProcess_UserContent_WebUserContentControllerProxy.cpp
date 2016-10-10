$NetBSD: patch-Source_WebKit2_UIProcess_UserContent_WebUserContentControllerProxy.cpp,v 1.1 2016/10/10 21:11:48 joerg Exp $

--- Source/WebKit2/UIProcess/UserContent/WebUserContentControllerProxy.cpp.orig	2016-10-09 14:17:57.000000000 +0000
+++ Source/WebKit2/UIProcess/UserContent/WebUserContentControllerProxy.cpp
@@ -116,7 +116,7 @@ void WebUserContentControllerProxy::addU
 void WebUserContentControllerProxy::removeUserScript(const API::UserScript& userScript)
 {
     for (WebProcessProxy* process : m_processes)
-        process->connection()->send(Messages::WebUserContentController::RemoveUserScript({ userScript.userScript().url().string() }), m_identifier);
+        process->connection()->send(Messages::WebUserContentController::RemoveUserScript(userScript.userScript().url()), m_identifier);
 
     m_userScripts->elements().removeAll(&userScript);
 }
@@ -140,7 +140,7 @@ void WebUserContentControllerProxy::addU
 void WebUserContentControllerProxy::removeUserStyleSheet(const API::UserStyleSheet& userStyleSheet)
 {
     for (WebProcessProxy* process : m_processes)
-        process->connection()->send(Messages::WebUserContentController::RemoveUserStyleSheet({ userStyleSheet.userStyleSheet().url().string() }), m_identifier);
+        process->connection()->send(Messages::WebUserContentController::RemoveUserStyleSheet(userStyleSheet.userStyleSheet().url()), m_identifier);
 
     m_userStyleSheets->elements().removeAll(&userStyleSheet);
 }
