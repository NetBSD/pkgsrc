$NetBSD: patch-extensions_apps.vala,v 1.1 2018/11/09 09:17:07 abs Exp $

Update to build against vala-0.42.0

--- extensions/apps.vala.orig	2015-08-30 11:56:26.000000000 +0000
+++ extensions/apps.vala
@@ -98,7 +98,7 @@ namespace Apps {
         }
 
         internal static async File create_profile (Gtk.Widget? proxy) {
-            string uuid = g_dbus_generate_guid ();
+            string uuid = DBus.generate_guid ();
             string config = Path.build_path (Path.DIR_SEPARATOR_S,
                 Midori.Paths.get_user_data_dir (), PACKAGE_NAME, "profiles", uuid);
             var folder = get_profile_folder ();
@@ -207,7 +207,7 @@ namespace Apps {
 
 #if !HAVE_WIN32
                 /* FIXME: Profiles are broken on win32 because of no multi instance support */
-                var profile = new Gtk.ToolButton.from_stock (Gtk.STOCK_ADD);
+                var profile = new Gtk.ToolButton.from_stock (Gtk.Stock.ADD);
                 profile.label = _("New _Profile");
                 profile.tooltip_text = _("Creates a new, independent profile and a launcher");
                 profile.use_underline = true;
@@ -219,7 +219,7 @@ namespace Apps {
                 toolbar.insert (profile, -1);
 #endif
 
-                var app = new Gtk.ToolButton.from_stock (Gtk.STOCK_ADD);
+                var app = new Gtk.ToolButton.from_stock (Gtk.Stock.ADD);
                 app.label = _("New _App");
                 app.tooltip_text = _("Creates a new app for a specific site");
                 app.use_underline = true;
@@ -265,7 +265,7 @@ namespace Apps {
                             store.get (iter, 0, out launcher);
                             try {
                                 launcher.file.trash (null);
-                                store.remove (iter);
+                                store.remove (ref iter);
 
                                 string filename = Midori.Download.clean_filename (launcher.name);
 #if HAVE_WIN32
@@ -385,7 +385,7 @@ namespace Apps {
         void on_render_button (Gtk.CellLayout column, Gtk.CellRenderer renderer,
             Gtk.TreeModel model, Gtk.TreeIter iter) {
 
-            renderer.set ("stock-id", Gtk.STOCK_DELETE,
+            renderer.set ("stock-id", Gtk.Stock.DELETE,
                           "stock-size", Gtk.IconSize.MENU);
         }
     }
