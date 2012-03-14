$NetBSD: patch-system_drivers_DC__Table.php,v 1.1 2012/03/14 16:35:29 taca Exp $

* Fix potential XSS vulnerability as Contao 2.11.2.

--- system/drivers/DC_Table.php.orig	2011-12-30 09:00:10.000000000 +0000
+++ system/drivers/DC_Table.php
@@ -557,10 +557,11 @@ class DC_Table extends DataContainer imp
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
