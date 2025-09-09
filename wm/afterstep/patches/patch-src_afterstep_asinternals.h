$NetBSD: patch-src_afterstep_asinternals.h,v 1.4 2025/09/09 22:07:36 gutteridge Exp $

Patch up gcc inline mess.

Add missing function prototypes.

--- src/afterstep/asinternals.h.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/afterstep/asinternals.h
@@ -575,6 +575,7 @@ void asdbus_shutdown();
 void asdbus_process_messages ();
 
 char *asdbus_RegisterSMClient(const char *sm_client_id);
+void asdbus_UnregisterSMClient(const char *sm_client_path);
 void asdbus_Notify(const char *summary, const char *body, int timeout);
 
 typedef enum {
@@ -587,6 +588,10 @@ Bool asdbus_GetCanLogout ();
 Bool asdbus_Logout (ASDbusLogoutMode mode, int timeout);
 Bool asdbus_GetCanShutdown ();
 Bool asdbus_Shutdown (int timeout);
+Bool asdbus_GetCanSuspend ();
+Bool asdbus_Suspend (int timeout);
+Bool asdbus_GetCanHibernate ();
+Bool asdbus_Hibernate (int timeout);
 Bool get_gnome_autosave ();
 
 /*************************** decorations.c ********************************/
@@ -689,8 +694,8 @@ void ParsePopupEntry (char *tline, FILE 
 
 
 /*************************** misc.c *********************************/
-inline void ungrab_window_buttons( Window w );
-inline void ungrab_window_keys (Window w );
+void ungrab_window_buttons( Window w );
+void ungrab_window_keys (Window w );
 void MyXGrabButton ( unsigned button, unsigned modifiers,
 				Window grab_window, Bool owner_events, unsigned event_mask,
 				int pointer_mode, int keyboard_mode, Window confine_to, Cursor cursor);
