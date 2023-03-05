$NetBSD: patch-inc_core_class.dc.core.php,v 1.4 2023/03/05 19:21:24 triaxx Exp $

Set pkgsrc compliant directory for /public.

--- inc/core/class.dc.core.php.orig	2022-05-13 06:25:40.000000000 +0000
+++ inc/core/class.dc.core.php
@@ -2120,7 +2120,7 @@ class dcCore
                     'Number of comments on feeds', ],
                 ['post_url_format', 'string', '{y}/{m}/{d}/{t}',
                     'Post URL format. {y}: year, {m}: month, {d}: day, {id}: post id, {t}: entry title', ],
-                ['public_path', 'string', 'public',
+                ['public_path', 'string', '@DOTCLEAR_PUBDIR@',
                     'Path to public directory, begins with a / for a full system path', ],
                 ['public_url', 'string', '/public',
                     'URL to public directory', ],
