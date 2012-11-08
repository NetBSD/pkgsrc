$NetBSD: patch-system_modules_core_classes_Frontend.php,v 1.1 2012/11/08 04:56:02 taca Exp $

Apply 5fee95e1850287107a93f516e54e2609802d050b to fix problem with empty
URL path and parameter from the repository <https://github.com/contao/core/>.

--- system/modules/core/classes/Frontend.php.orig	2012-10-30 08:24:57.000000000 +0000
+++ system/modules/core/classes/Frontend.php
@@ -236,8 +236,8 @@ abstract class Frontend extends \Control
 			}
 		}
 
-		// Return if the alias is empty (see #4702)
-		if ($arrFragments[0] == '')
+		// Return if the alias is empty (see #4702 and #4972)
+		if ($arrFragments[0] == '' && count($arrFragments) > 1)
 		{
 			return false;
 		}
