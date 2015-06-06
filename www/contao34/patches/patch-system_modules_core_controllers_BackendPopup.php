$NetBSD: patch-system_modules_core_controllers_BackendPopup.php,v 1.1 2015/06/06 03:31:01 taca Exp $

Security improvement as Contao 3.2.21.

--- system/modules/core/controllers/BackendPopup.php.orig	2015-03-27 08:53:59.000000000 +0000
+++ system/modules/core/controllers/BackendPopup.php
@@ -128,7 +128,7 @@ class BackendPopup extends \Backend
 		$this->Template->ctime = \Date::parse(\Config::get('datimFormat'), $objFile->ctime);
 		$this->Template->mtime = \Date::parse(\Config::get('datimFormat'), $objFile->mtime);
 		$this->Template->atime = \Date::parse(\Config::get('datimFormat'), $objFile->atime);
-		$this->Template->path = $this->strFile;
+		$this->Template->path = specialchars($this->strFile);
 
 		$this->output();
 	}
