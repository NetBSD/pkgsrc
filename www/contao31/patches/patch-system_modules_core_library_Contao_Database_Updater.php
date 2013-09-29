$NetBSD: patch-system_modules_core_library_Contao_Database_Updater.php,v 1.1 2013/09/29 03:40:32 taca Exp $

Workaround for contao 3.1.0 update; make proper update of accordion
content element.

--- system/modules/core/library/Contao/Database/Updater.php.orig	2013-09-24 08:33:35.000000000 +0000
+++ system/modules/core/library/Contao/Database/Updater.php
@@ -455,9 +455,9 @@ class Updater extends \Controller
 		}
 
 		// Adjust the accordion elements
-		$this->Database->query("UPDATE `tl_content` SET `type`='accordionStart' WHERE `type`='accordion' AND `mooType`='start'");
-		$this->Database->query("UPDATE `tl_content` SET `type`='accordionStop' WHERE `type`='accordion' AND `mooType`='stop'");
-		$this->Database->query("UPDATE `tl_content` SET `type`='accordionSingle' WHERE `type`='accordion' AND `mooType`='single'");
+		$this->Database->query("UPDATE `tl_content` SET `type`='accordionStart' WHERE `type`='accordion' AND `mooType`='mooStart'");
+		$this->Database->query("UPDATE `tl_content` SET `type`='accordionStop' WHERE `type`='accordion' AND `mooType`='mooStop'");
+		$this->Database->query("UPDATE `tl_content` SET `type`='accordionSingle' WHERE `type`='accordion' AND `mooType`='mooSingle'");
 
 		// White-space is now in the "alignment" section (see #4519)
 		$this->Database->query("UPDATE `tl_style` SET `alignment`=1 WHERE `whitespace`!=''");
