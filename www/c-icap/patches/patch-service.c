$NetBSD: patch-service.c,v 1.2 2015/06/12 23:39:11 taca Exp $

Avoid CONF name colision.

--- service.c.orig	2013-10-25 14:59:57.000000000 +0000
+++ service.c
@@ -368,7 +368,7 @@ ci_service_module_t *add_service(ci_serv
      xdata = &service_extra_data_list[services_num];
      init_extra_data(xdata, service->mod_name);
      if (service->mod_init_service) {
-          ret = service->mod_init_service(xdata, &CONF);
+          ret = service->mod_init_service(xdata, &ci_CONF);
           if (ret != CI_OK)
                xdata->status = CI_SERVICE_ERROR;
           else
@@ -449,7 +449,7 @@ int post_init_services()
                xdata = &service_extra_data_list[i];
                if ( xdata->status == CI_SERVICE_OK) {
                     ret = service_list[i]->
-                        mod_post_init_service(xdata, &CONF);
+                        mod_post_init_service(xdata, &ci_CONF);
                     if (ret != CI_OK)
                         xdata->status = CI_SERVICE_ERROR;
                }
@@ -608,7 +608,7 @@ ci_service_module_t *load_c_service(cons
      ci_service_module_t *service = NULL;
      CI_DLIB_HANDLE service_handle;
 
-     service_handle = ci_module_load(service_file, CONF.SERVICES_DIR);
+     service_handle = ci_module_load(service_file, ci_CONF.SERVICES_DIR);
      if (!service_handle)
           return NULL;
      service = ci_module_sym(service_handle, "service");
