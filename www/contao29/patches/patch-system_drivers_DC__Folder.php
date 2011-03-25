$NetBSD: patch-system_drivers_DC__Folder.php,v 1.1 2011/03/25 16:52:08 taca Exp $

Fix code editor problem applying r630 from repository.

--- system/drivers/DC_Folder.php.orig	2011-03-02 13:03:27.000000000 +0000
+++ system/drivers/DC_Folder.php
@@ -1403,7 +1403,8 @@ window.addEvent(\'domready\', function()
 		// Prepare the code editor
 		if ($GLOBALS['TL_CONFIG']['useCE'])
 		{
-			$this->ceField = 'ctrl_source';
+			$this->ceFields = array('ctrl_source');
+			$this->ceField = 'ctrl_source'; // Backwards compatibility
 			$this->language = $GLOBALS['TL_LANGUAGE'];
 			$this->extension = $objFile->extension;
 
