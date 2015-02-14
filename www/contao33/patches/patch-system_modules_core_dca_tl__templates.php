$NetBSD: patch-system_modules_core_dca_tl__templates.php,v 1.1.2.1 2015/02/14 10:07:52 tron Exp $

Fix for CVE-2015-0269.

--- system/modules/core/dca/tl_templates.php.orig	2014-11-24 09:12:58.000000000 +0000
+++ system/modules/core/dca/tl_templates.php
@@ -141,12 +141,20 @@ class tl_templates extends Backend
 
 	/**
 	 * Add the breadcrumb menu
+	 *
+	 * @throws RuntimeException
 	 */
 	public function addBreadcrumb()
 	{
 		// Set a new node
 		if (isset($_GET['node']))
 		{
+			// Check the path (thanks to Arnaud Buchoux)
+			if (Validator::isInsecurePath(Input::get('node', true)))
+			{
+				throw new RuntimeException('Insecure path ' . Input::get('node', true));
+			}
+
 			$this->Session->set('tl_templates_node', Input::get('node', true));
 			$this->redirect(preg_replace('/(&|\?)node=[^&]*/', '', Environment::get('request')));
 		}
@@ -158,6 +166,12 @@ class tl_templates extends Backend
 			return;
 		}
 
+		// Check the path (thanks to Arnaud Buchoux)
+		if (Validator::isInsecurePath($strNode))
+		{
+			throw new RuntimeException('Insecure path ' . $strNode);
+		}
+
 		// Currently selected folder does not exist
 		if (!is_dir(TL_ROOT . '/' . $strNode))
 		{
