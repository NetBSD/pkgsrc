$NetBSD: patch-system_modules_frontend_ModuleArticlenav.php,v 1.1 2011/10/10 16:35:11 taca Exp $

* Fix potential XSS vulnerability, r1044.

--- system/modules/frontend/ModuleArticlenav.php.orig	2011-03-02 13:03:27.000000000 +0000
+++ system/modules/frontend/ModuleArticlenav.php
@@ -93,7 +93,7 @@ class ModuleArticlenav extends Module
 				return '';
 			}
 
-			$strAlias = (strlen($this->objArticles->alias) && !$GLOBALS['TL_CONFIG']['disableAlias']) ? $this->objArticles->alias : $this->objArticles->id;
+			$strAlias = ($this->objArticles->alias != '' && !$GLOBALS['TL_CONFIG']['disableAlias']) ? $this->objArticles->alias : $this->objArticles->id;
 			$this->redirect($this->addToUrl('articles=' . $strAlias));
 		}
 
