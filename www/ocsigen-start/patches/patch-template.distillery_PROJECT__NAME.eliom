$NetBSD: patch-template.distillery_PROJECT__NAME.eliom,v 1.1 2018/06/06 10:50:51 jaapb Exp $

Lwt_log is deprecated
--- template.distillery/PROJECT_NAME.eliom.orig	2018-03-09 16:47:43.000000000 +0000
+++ template.distillery/PROJECT_NAME.eliom
@@ -70,7 +70,7 @@ let%server () =
    Lwt_log.ign_info ~section "This is an information";
    (or ign_debug, ign_warning, ign_error etc.)
  *)
-let%server _ =
+(* let%server _ =
   if Eliom_config.get_debugmode ()
   then begin
     ignore
@@ -83,4 +83,4 @@ let%server _ =
         : unit ) ];
     (* Lwt_log_core.add_rule "*" Lwt_log.Debug *)
     Lwt_log_core.add_rule "%%%MODULE_NAME%%%*" Lwt_log.Debug
-  end
+  end *)
