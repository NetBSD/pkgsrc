$NetBSD: patch-libpanel-applet_panel-applet-factory.c,v 1.1 2014/12/16 10:46:32 prlw1 Exp $

Help prevent race condition at session start.
https://mail.gnome.org/archives/commits-list/2012-May/msg05607.html

--- libpanel-applet/panel-applet-factory.c.orig	2010-06-22 23:00:28.000000000 +0000
+++ libpanel-applet/panel-applet-factory.c
@@ -210,7 +210,7 @@ static const GDBusInterfaceVTable interf
 static GDBusNodeInfo *introspection_data = NULL;
 
 static void
-on_name_acquired (GDBusConnection    *connection,
+on_bus_acquired (GDBusConnection    *connection,
 		  const gchar        *name,
 		  PanelAppletFactory *factory)
 {
@@ -251,8 +251,8 @@ panel_applet_factory_register_service (P
 	g_bus_own_name (G_BUS_TYPE_SESSION,
 			service_name,
 			G_BUS_NAME_OWNER_FLAGS_NONE,
+			(GBusNameAcquiredCallback) on_bus_acquired,
 			NULL,
-			(GBusNameAcquiredCallback) on_name_acquired,
 			(GBusNameLostCallback) on_name_lost,
 			factory, NULL);
 	g_free (service_name);
