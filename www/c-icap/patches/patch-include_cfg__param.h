$NetBSD: patch-include_cfg__param.h,v 1.2 2015/06/12 23:39:11 taca Exp $

Avoid CONF name colision.

--- include/cfg_param.h.orig	2013-10-25 14:59:54.000000000 +0000
+++ include/cfg_param.h
@@ -126,7 +126,7 @@ struct cfg_default_value{
 #define ALIAS_TABLE 2
 
 #ifndef CI_BUILD_LIB
-extern struct ci_server_conf CONF;
+extern struct ci_server_conf ci_CONF;
 
 struct cfg_default_value * cfg_default_value_store(void *param, void *value,int size);
 struct cfg_default_value * cfg_default_value_replace(void *param, void *value);
