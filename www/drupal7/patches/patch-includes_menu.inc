$NetBSD: patch-includes_menu.inc,v 1.1 2018/10/03 10:58:15 prlw1 Exp $

Issue #2925449
Function each() is deprecated since PHP 7.2
commit 28de6772813387bf02a4bf6f75b9119c4c20a3f4

--- includes/menu.inc.orig	2018-04-25 15:32:27.000000000 +0000
+++ includes/menu.inc
@@ -576,7 +576,8 @@ function _menu_load_objects(&$item, &$ma
           // 'load arguments' in the hook_menu() entry, but they need
           // some processing. In this case the $function is the key to the
           // load_function array, and the value is the list of arguments.
-          list($function, $args) = each($function);
+          $args = current($function);
+          $function = key($function);
           $load_functions[$index] = $function;
 
           // Some arguments are placeholders for dynamic items to process.
@@ -2402,7 +2403,8 @@ function menu_set_active_trail($new_trai
       // a stripped down menu tree containing the active trail only, in case
       // the given menu has not been built in this request yet.
       $tree = menu_tree_page_data($preferred_link['menu_name'], NULL, TRUE);
-      list($key, $curr) = each($tree);
+      $curr = current($tree);
+      next($tree);
     }
     // There is no link for the current path.
     else {
@@ -2432,7 +2434,8 @@ function menu_set_active_trail($new_trai
         }
         $tree = $curr['below'] ? $curr['below'] : array();
       }
-      list($key, $curr) = each($tree);
+      $curr = current($tree);
+      next($tree);
     }
     // Make sure the current page is in the trail to build the page title, by
     // appending either the preferred link or the menu router item for the
