$NetBSD: patch-midori_midori-notebook.vala,v 1.1 2018/11/09 09:17:07 abs Exp $

Update to build against vala-0.42.0

--- midori/midori-notebook.vala.orig	2015-08-30 11:56:26.000000000 +0000
+++ midori/midori-notebook.vala
@@ -10,7 +10,7 @@
 */
 
 namespace Midori {
-    protected class Tally : Gtk.EventBox {
+    internal class Tally : Gtk.EventBox {
         public Midori.Tab tab { get; set; }
         Gtk.Spinner spinner;
         public Gtk.Label label;
@@ -22,7 +22,7 @@ namespace Midori {
         public bool close_button_left { get; set; default = false; }
         public bool close_button_visible { get; set; default = false; }
 
-        protected Tally (Midori.Tab tab) {
+        internal Tally (Midori.Tab tab) {
             this.tab = tab;
             box = new Gtk.HBox (false, 1);
             add (box);
@@ -393,7 +393,7 @@ namespace Midori {
                         child.destroy ();
             });
             menu.add (action_other);
-            var action_close = new Midori.ContextAction ("TabClose", null, null, Gtk.STOCK_CLOSE);
+            var action_close = new Midori.ContextAction ("TabClose", null, null, Gtk.Stock.CLOSE);
             action_close.activate.connect (()=>{
                 tab.destroy ();
             });
