$NetBSD: patch-system_drivers_DC__Table.php,v 1.1 2012/03/14 16:42:02 taca Exp $

* Fix potential XSS vulnerability as Contao 2.11.2.

--- system/drivers/DC_Table.php.orig	2011-03-02 13:03:27.000000000 +0000
+++ system/drivers/DC_Table.php
@@ -562,10 +562,11 @@ class DC_Table extends DataContainer imp
 							$label = $i;
 						}
 
+						// Always encode special characters (thanks to Oliver Klee)
 						$return .= '
   <tr>
     <td'.$class.'><span class="tl_label">'.$label.': </span></td>
-    <td'.$class.'>'.$v.'</td>
+    <td'.$class.'>'.specialchars($v).'</td>
   </tr>';
 					}
 				}
