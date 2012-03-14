$NetBSD: patch-system_modules_backend_StyleSheets.php,v 1.1 2012/03/14 16:35:29 taca Exp $

* Make sure to variable contains Array.

--- system/modules/backend/StyleSheets.php.orig	2011-12-30 09:00:10.000000000 +0000
+++ system/modules/backend/StyleSheets.php
@@ -237,7 +237,7 @@ class StyleSheets extends Backend
 			// Width
 			$row['width'] = deserialize($row['width']);
 
-			if ($row['width']['value'] != '')
+			if (is_array($row['width']) && $row['width']['value'] != '')
 			{
 				$return .= $lb . 'width:' . $row['width']['value'] . (($row['width']['value'] == 'auto') ? '' : $row['width']['unit']) . ';';
 			}
@@ -245,7 +245,7 @@ class StyleSheets extends Backend
 			// Height
 			$row['height'] = deserialize($row['height']);
 
-			if ($row['height']['value'] != '')
+			if (is_array($row['height']) && $row['height']['value'] != '')
 			{
 				$return .= $lb . 'height:' . $row['height']['value'] . (($row['height']['value'] == 'auto') ? '' : $row['height']['unit']) . ';';
 			}
@@ -253,7 +253,7 @@ class StyleSheets extends Backend
 			// Min-width
 			$row['minwidth'] = deserialize($row['minwidth']);
 
-			if ($row['minwidth']['value'] != '')
+			if (is_array($row['minwidth']) && $row['minwidth']['value'] != '')
 			{
 				$return .= $lb . 'min-width:' . $row['minwidth']['value'] . $row['minwidth']['unit'] . ';';
 			}
@@ -261,7 +261,7 @@ class StyleSheets extends Backend
 			// Min-height
 			$row['minheight'] = deserialize($row['minheight']);
 
-			if ($row['minheight']['value'] != '')
+			if (is_array($row['minheight']) && $row['minheight']['value'] != '')
 			{
 				$return .= $lb . 'min-height:' . $row['minheight']['value'] . $row['minheight']['unit'] . ';';
 			}
@@ -269,7 +269,7 @@ class StyleSheets extends Backend
 			// Max-width
 			$row['maxwidth'] = deserialize($row['maxwidth']);
 
-			if ($row['maxwidth']['value'] != '')
+			if (is_array($row['maxwidth']) && $row['maxwidth']['value'] != '')
 			{
 				$return .= $lb . 'max-width:' . $row['maxwidth']['value'] . $row['maxwidth']['unit'] . ';';
 			}
@@ -277,7 +277,7 @@ class StyleSheets extends Backend
 			// Max-height
 			$row['maxheight'] = deserialize($row['maxheight']);
 
-			if ($row['maxheight']['value'] != '')
+			if (is_array($row['maxheight']) && $row['maxheight']['value'] != '')
 			{
 				$return .= $lb . 'max-height:' . $row['maxheight']['value'] . $row['maxheight']['unit'] . ';';
 			}
@@ -832,7 +832,7 @@ class StyleSheets extends Backend
 			// Border spacing
 			$row['borderspacing'] = deserialize($row['borderspacing']);
 
-			if ($row['borderspacing']['value'] != '')
+			if (is_array($row['borderspacing']) && $row['borderspacing']['value'] != '')
 			{
 				$return .= $lb . 'border-spacing:' . $row['borderspacing']['value'] . $row['borderspacing']['unit'] . ';';
 			}
@@ -845,9 +845,9 @@ class StyleSheets extends Backend
 			$row['lineheight'] = deserialize($row['lineheight']);
 
 			// Try to shorten the definition
-			if ($row['fontfamily'] != '' && $row['fontfamily'] != 'inherit' && $row['fontsize']['value'] != '' && $row['fontsize']['value'] != 'inherit')
+			if ($row['fontfamily'] != '' && $row['fontfamily'] != 'inherit' && is_array($row['fontsize']) && $row['fontsize']['value'] != '' && $row['fontsize']['value'] != 'inherit')
 			{
-				$return .= $lb . 'font:' . $row['fontsize']['value'] . $row['fontsize']['unit'] . (($row['lineheight']['value'] != '') ? '/' . $row['lineheight']['value'] . $row['lineheight']['unit'] : '') . ' ' . $row['fontfamily'] . ';';
+				$return .= $lb . 'font:' . $row['fontsize']['value'] . $row['fontsize']['unit'] . ((is_array($row['lineheight']) && $row['lineheight']['value'] != '') ? '/' . $row['lineheight']['value'] . $row['lineheight']['unit'] : '') . ' ' . $row['fontfamily'] . ';';
 			}
 			else
 			{
@@ -858,13 +858,13 @@ class StyleSheets extends Backend
 				}
 
 				// Font size
-				if ($row['fontsize']['value'] != '')
+				if (is_array($row['fontsize']) && $row['fontsize']['value'] != '')
 				{
 					$return .= $lb . 'font-size:' . $row['fontsize']['value'] . $row['fontsize']['unit'] . ';';
 				}
 
 				// Line height
-				if ($row['lineheight']['value'] != '')
+				if (is_array($row['lineheight']) && $row['lineheight']['value'] != '')
 				{
 					$return .= $lb . 'line-height:' . $row['lineheight']['value'] . $row['lineheight']['unit'] . ';';
 				}
@@ -939,7 +939,7 @@ class StyleSheets extends Backend
 			// Text indent
 			$row['textindent'] = deserialize($row['textindent']);
 
-			if ($row['textindent']['value'] != '')
+			if (is_array($row['textindent']) && $row['textindent']['value'] != '')
 			{
 				$return .= $lb . 'text-indent:' . $row['textindent']['value'] . $row['textindent']['unit'] . ';';
 			}
@@ -947,7 +947,7 @@ class StyleSheets extends Backend
 			// Letter spacing
 			$row['letterspacing'] = deserialize($row['letterspacing']);
 
-			if ($row['letterspacing']['value'] != '')
+			if (is_array($row['letterspacing']) && $row['letterspacing']['value'] != '')
 			{
 				$return .= $lb . 'letter-spacing:' . $row['letterspacing']['value'] . $row['letterspacing']['unit'] . ';';
 			}
@@ -955,7 +955,7 @@ class StyleSheets extends Backend
 			// Word spacing
 			$row['wordspacing'] = deserialize($row['wordspacing']);
 
-			if ($row['wordspacing']['value'] != '')
+			if (is_array($row['wordspacing']) && $row['wordspacing']['value'] != '')
 			{
 				$return .= $lb . 'word-spacing:' . $row['wordspacing']['value'] . $row['wordspacing']['unit'] . ';';
 			}
