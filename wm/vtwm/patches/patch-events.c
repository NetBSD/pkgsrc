$NetBSD: patch-events.c,v 1.1 2025/01/11 14:47:07 wiz Exp $

Apply fix for PR 58979 (twm) for vtwm.

--- events.c.orig	2018-04-21 01:39:31.000000000 -0400
+++ events.c	2025-01-11 09:08:42.572757158 -0500
@@ -3145,7 +3145,9 @@ HandleLeaveNotify(void)
     if (FocusRoot)
     {
 
-      if (Event.xcrossing.detail != NotifyInferior)
+      if (Event.xcrossing.detail != NotifyInferior &&
+	  Event.xcrossing.detail != NotifyVirtual &&
+	  Event.xcrossing.detail != NotifyNonlinearVirtual)
       {
 
 	/*
