$NetBSD: patch-src_postorius_static_postorius_js_held__messages.js,v 1.1 2026/05/07 20:50:31 wiz Exp $

https://gitlab.com/mailman/postorius/-/commit/c4706abd05ba6bcf472fc674b160d3a9d6a4868b

--- src/postorius/static/postorius/js/held_messages.js.orig	2023-01-04 06:22:36.459728000 +0000
+++ src/postorius/static/postorius/js/held_messages.js
@@ -9,7 +9,7 @@ var loadjs = function(rest_url, error_message) {
       url: rest_url + msgid,
       success: function(data) {
         $('#message-source-btn').attr('href', rest_url + msgid + '?raw')
-        $('#message-title').html(data.subject);
+        $('#message-title').text(data.subject);
         $('.modal-footer form input[name="msgid"]').attr('value', msgid);
         if (data.msg.body) {
           $('#held-message-content').text(data.msg.body);
