$NetBSD: patch-include_cfg__param.h,v 1.1 2015/06/02 20:02:45 joerg Exp $

--- include/cfg_param.h.orig	2015-05-28 20:05:29.000000000 +0000
+++ include/cfg_param.h
@@ -121,7 +121,7 @@ struct cfg_default_value{
 #define ALIAS_TABLE 2
 
 #ifndef CI_BUILD_LIB
-extern struct ci_server_conf CONF;
+extern struct ci_server_conf ci_CONF;
 
 struct cfg_default_value * cfg_default_value_store(void *param, void *value,int size);
 struct cfg_default_value * cfg_default_value_replace(void *param, void *value);
