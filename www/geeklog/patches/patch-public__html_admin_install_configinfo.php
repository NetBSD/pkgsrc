$NetBSD: patch-public__html_admin_install_configinfo.php,v 1.1 2022/12/23 13:47:42 taca Exp $

* Output Content-Type header explicitly.

--- public_html/admin/install/configinfo.php.orig	2022-09-27 15:13:22.000000000 +0000
+++ public_html/admin/install/configinfo.php
@@ -120,4 +120,6 @@ $display .= '
 </body>
 </html>';
 
+header('Content-Type: text/html; charset=' . COM_getCharset());
+
 echo $display;
