$NetBSD: patch-src_plugins_accessible_widgets_itemviews.cpp,v 1.1 2013/08/29 13:00:41 joerg Exp $

--- src/plugins/accessible/widgets/itemviews.cpp.orig	2013-07-12 12:18:31.000000000 +0000
+++ src/plugins/accessible/widgets/itemviews.cpp
@@ -393,7 +393,7 @@ bool QAccessibleTable2::unselectColumn(i
     QModelIndex index = view()->model()->index(0, column, view()->rootIndex());
     if (!index.isValid() || view()->selectionMode() & QAbstractItemView::NoSelection)
         return false;
-    view()->selectionModel()->select(index, QItemSelectionModel::Columns & QItemSelectionModel::Deselect);
+    view()->selectionModel()->select(index, QItemSelectionModel::SelectionFlags(QItemSelectionModel::Columns & QItemSelectionModel::Deselect));
     return true;
 }
 
