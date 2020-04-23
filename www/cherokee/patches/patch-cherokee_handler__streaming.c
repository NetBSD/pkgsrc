$NetBSD: patch-cherokee_handler__streaming.c,v 1.1 2020/04/23 15:46:01 nia Exp $

Fix build with ffmpeg4.

--- cherokee/handler_streaming.c.orig	2011-10-12 18:07:44.000000000 +0000
+++ cherokee/handler_streaming.c
@@ -111,7 +111,7 @@ cherokee_handler_streaming_free (cheroke
 	}
 
 	if (hdl->avformat != NULL) {
-		av_close_input_file (hdl->avformat);
+		avformat_close_input (&hdl->avformat);
 	}
 
 	cherokee_buffer_mrproper (&hdl->local_file);
@@ -312,14 +312,14 @@ open_media_file (cherokee_handler_stream
 
 	/* Open the media stream
 	 */
-	re = av_open_input_file (&hdl->avformat, hdl->local_file.buf, NULL, 0, NULL);
+	re = avformat_open_input (&hdl->avformat, hdl->local_file.buf, NULL, NULL);
 	if (re != 0) {
 		goto error;
 	}
 
 	/* Read the info
 	 */
-	re = av_find_stream_info (hdl->avformat);
+	re = avformat_find_stream_info (hdl->avformat, NULL);
 	if (re < 0) {
 		goto error;
 	}
@@ -327,7 +327,7 @@ open_media_file (cherokee_handler_stream
 	return ret_ok;
 error:
 	if (hdl->avformat != NULL) {
-		av_close_input_file (hdl->avformat);
+		avformat_close_input (&hdl->avformat);
 		hdl->avformat = NULL;
 	}
 
@@ -380,7 +380,7 @@ set_auto_rate (cherokee_handler_streamin
 	if (likely (secs > 0)) {
 		long tmp;
 
-		tmp = (hdl->avformat->file_size / secs);
+		tmp = (hdl->handler_file->info->st_size / secs);
 		if (tmp > rate) {
 			rate = tmp;
 			TRACE(ENTRIES, "New rate: %d bytes/s\n", rate);
