$NetBSD: patch-lib_Menu.cc,v 1.1 2018/10/12 18:00:55 he Exp $

Sunpro has problems with a non-const const_reverse_iterator.

--- lib/Menu.cc.orig	2016-07-10 16:31:38.000000000 +0000
+++ lib/Menu.cc
@@ -37,6 +37,7 @@
 
 #include <cstdio>
 #include <assert.h>
+#include <cstdlib>
 
 
 bt::MenuStyle **bt::MenuStyle::styles = 0;
@@ -365,7 +366,7 @@ unsigned int bt::Menu::insertItem(const 
   } else {
     index = std::min(static_cast<size_t>(index), _items.size());
     it = _items.begin();
-    std::advance<ItemList::iterator, signed>(it, index);
+    std::advance(it, index);
   }
 
   it = _items.insert(it, item);
@@ -516,7 +517,7 @@ void bt::Menu::removeItem(unsigned int i
 
 void bt::Menu::removeIndex(unsigned int index) {
   ItemList::iterator it = _items.begin();
-  std::advance<ItemList::iterator, signed>(it, index);
+  std::advance(it, index);
   if (it == _items.end())
     return; // item not found
   removeItemByIterator(it);
@@ -1037,7 +1038,7 @@ void bt::Menu::keyPressEvent(const XKeyE
     const ItemList::const_iterator &end = _items.end();
     ItemList::const_iterator anchor = _items.begin();
     if (_active_index != ~0u) {
-      std::advance<ItemList::const_iterator, signed>(anchor, _active_index);
+      std::advance(anchor, _active_index);
 
       // go one paste the current active index
       if (anchor != end && !anchor->separator)
@@ -1054,11 +1055,10 @@ void bt::Menu::keyPressEvent(const XKeyE
   }
 
   case XK_Up: {
-    ItemList::const_reverse_iterator anchor = _items.rbegin();
-    const ItemList::const_reverse_iterator &end = _items.rend();
+    ItemList::reverse_iterator anchor = _items.rbegin();
+    const ItemList::reverse_iterator &end = _items.rend();
     if (_active_index != ~0u) {
-      std::advance<ItemList::const_reverse_iterator, signed>
-        (anchor, _items.size() - _active_index - 1);
+      std::advance(anchor, _items.size() - _active_index - 1);
 
       // go one item past the current active index
       if (anchor != end && !anchor->separator)
@@ -1067,7 +1067,7 @@ void bt::Menu::keyPressEvent(const XKeyE
 
     if (anchor == end) anchor = _items.rbegin();
 
-    ItemList::const_reverse_iterator it =
+    ItemList::reverse_iterator it =
       std::find_if(anchor, end, InteractMatch());
     if (it != end)
       activateIndex(it->indx);
@@ -1075,8 +1075,8 @@ void bt::Menu::keyPressEvent(const XKeyE
   }
 
   case XK_Home: {
-    const ItemList::const_iterator &end = _items.end();
-    ItemList::const_iterator it = _items.begin();
+    const ItemList::iterator &end = _items.end();
+    ItemList::iterator it = _items.begin();
     it = std::find_if(it, end, InteractMatch());
     if (it != end)
       activateIndex(it->indx);
@@ -1084,8 +1084,8 @@ void bt::Menu::keyPressEvent(const XKeyE
   }
 
   case XK_End: {
-    const ItemList::const_reverse_iterator &end = _items.rend();
-    ItemList::const_reverse_iterator it = _items.rbegin();
+    const ItemList::reverse_iterator &end = _items.rend();
+    ItemList::reverse_iterator it = _items.rbegin();
     it = std::find_if(it, end, InteractMatch());
     if (it != end)
       activateIndex(it->indx);
