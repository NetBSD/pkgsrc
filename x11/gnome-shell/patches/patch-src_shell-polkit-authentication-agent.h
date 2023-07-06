$NetBSD: patch-src_shell-polkit-authentication-agent.h,v 1.1 2023/07/06 21:45:25 wiz Exp $

Fix build with polkit-121.

--- src/shell-polkit-authentication-agent.h.orig	2021-06-10 11:33:01.889923000 +0000
+++ src/shell-polkit-authentication-agent.h
@@ -14,8 +14,10 @@
 
 G_BEGIN_DECLS
 
+#ifndef HAVE_POLKIT_AUTOCLEANUP
 /* Polkit doesn't have g_autoptr support, thus we have to manually set the autoptr function here */
 G_DEFINE_AUTOPTR_CLEANUP_FUNC (PolkitAgentListener, g_object_unref)
+#endif
 
 #define SHELL_TYPE_POLKIT_AUTHENTICATION_AGENT (shell_polkit_authentication_agent_get_type())
 
