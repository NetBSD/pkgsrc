$NetBSD: patch-gtk_gtklabel.c,v 1.2 2020/07/23 09:09:48 maya Exp $

Don't deref label before we check if it's (among other things)
non-NULL.

Fixes crash with glade, reproduce with:
1. New project
2. Toplevel -> GtkAssistant
3. Press assistant anywhere

Note: this patch was rejected on GTK upstream and glade was patched
to avoid this crash. Will become unnecessary once gtk3 or glade are
updated.

--- gtk/gtklabel.c.orig	2020-02-03 11:45:12.000000000 +0000
+++ gtk/gtklabel.c
@@ -2297,10 +2297,12 @@ void
 gtk_label_set_attributes (GtkLabel         *label,
                           PangoAttrList    *attrs)
 {
-  GtkLabelPrivate *priv = label->priv;
+  GtkLabelPrivate *priv;
 
   g_return_if_fail (GTK_IS_LABEL (label));
 
+  priv = label->priv;
+
   if (attrs)
     pango_attr_list_ref (attrs);
 
