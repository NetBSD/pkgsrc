$NetBSD: patch-media_libstagefright_binding_include_mp4__demuxer_DecoderData.h,v 1.1 2017/06/14 11:28:44 ryoon Exp $

--- media/libstagefright/binding/include/mp4_demuxer/DecoderData.h.orig	2017-06-05 20:45:14.000000000 +0000
+++ media/libstagefright/binding/include/mp4_demuxer/DecoderData.h
@@ -19,11 +19,13 @@ namespace stagefright
 class MetaData;
 }
 
+#ifdef MOZ_RUST_MP4PARSE
 extern "C" {
 typedef struct mp4parse_track_info mp4parse_track_info;
 typedef struct mp4parse_track_audio_info mp4parse_track_audio_info;
 typedef struct mp4parse_track_video_info mp4parse_track_video_info;
 }
+#endif // MOZ_RUST_MP4PARSE
 
 namespace mp4_demuxer
 {
@@ -71,8 +73,10 @@ public:
   void Update(const stagefright::MetaData* aMetaData,
               const char* aMimeType);
 
+#ifdef MOZ_RUST_MP4PARSE
   void Update(const mp4parse_track_info* track,
               const mp4parse_track_audio_info* audio);
+#endif // MOZ_RUST_MP4PARSE
 
   virtual bool IsValid() const override;
 };
@@ -85,8 +89,10 @@ public:
   void Update(const stagefright::MetaData* aMetaData,
               const char* aMimeType);
 
+#ifdef MOZ_RUST_MP4PARSE
   void Update(const mp4parse_track_info* track,
               const mp4parse_track_video_info* video);
+#endif // MOZ_RUST_MP4PARSE
 
   virtual bool IsValid() const override;
 };
