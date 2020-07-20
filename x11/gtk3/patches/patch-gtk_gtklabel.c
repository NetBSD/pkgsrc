$NetBSD: patch-gtk_gtklabel.c,v 1.1 2020/07/20 14:39:35 maya Exp $

Don't deref label before we check if it's (among other things)
non-NULL.

Fixes crash with glade, reproduce with:
1. New project
2. Toplevel -> GtkAssistant
3. Press assistant anywhere

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
 
