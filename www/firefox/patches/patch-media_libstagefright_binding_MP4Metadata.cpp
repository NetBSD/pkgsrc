$NetBSD: patch-media_libstagefright_binding_MP4Metadata.cpp,v 1.1 2017/06/14 11:28:44 ryoon Exp $

--- media/libstagefright/binding/MP4Metadata.cpp.orig	2017-06-05 20:45:14.000000000 +0000
+++ media/libstagefright/binding/MP4Metadata.cpp
@@ -19,14 +19,18 @@
 #include "mp4_demuxer/MP4Metadata.h"
 #include "mp4_demuxer/Stream.h"
 #include "MediaPrefs.h"
+#ifdef MOZ_RUST_MP4PARSE
 #include "mp4parse.h"
+#endif // MOZ_RUST_MP4PARSE
 
 #include <limits>
 #include <stdint.h>
 #include <vector>
 
 
+#ifdef MOZ_RUST_MP4PARSE
 struct FreeMP4Parser { void operator()(mp4parse_parser* aPtr) { mp4parse_free(aPtr); } };
+#endif // MOZ_RUST_MP4PARSE
 
 using namespace stagefright;
 
@@ -101,6 +105,7 @@ private:
   bool mCanSeek;
 };
 
+#ifdef MOZ_RUST_MP4PARSE
 // Wrap an mp4_demuxer::Stream to remember the read offset.
 
 class RustStreamAdaptor {
@@ -145,9 +150,11 @@ private:
   RustStreamAdaptor mRustSource;
   mozilla::UniquePtr<mp4parse_parser, FreeMP4Parser> mRustParser;
 };
+#endif // MOZ_RUST_MP4PARSE
 
 MP4Metadata::MP4Metadata(Stream* aSource)
  : mStagefright(MakeUnique<MP4MetadataStagefright>(aSource))
+#ifdef MOZ_RUST_MP4PARSE
  , mRust(MakeUnique<MP4MetadataRust>(aSource))
  , mPreferRust(false)
  , mReportedAudioTrackTelemetry(false)
@@ -155,6 +162,7 @@ MP4Metadata::MP4Metadata(Stream* aSource
 #ifndef RELEASE_OR_BETA
  , mRustTestMode(MediaPrefs::RustTestMode())
 #endif
+#endif // MOZ_RUST_MP4PARSE
 {
 }
 
@@ -186,6 +194,7 @@ MP4Metadata::GetNumberTracks(mozilla::Tr
 {
   uint32_t numTracks = mStagefright->GetNumberTracks(aType);
 
+#ifdef MOZ_RUST_MP4PARSE
   if (!mRust) {
     return numTracks;
   }
@@ -211,10 +220,12 @@ MP4Metadata::GetNumberTracks(mozilla::Tr
     mPreferRust = true;
     return numTracksRust;
   }
+#endif // MOZ_RUST_MP4PARSE
 
   return numTracks;
 }
 
+#ifdef MOZ_RUST_MP4PARSE
 bool MP4Metadata::ShouldPreferRust() const {
   if (!mRust) {
     return false;
@@ -245,6 +256,7 @@ bool MP4Metadata::ShouldPreferRust() con
   // Otherwise, fall back.
   return false;
 }
+#endif // MOZ_RUST_MP4PARSE
 
 mozilla::UniquePtr<mozilla::TrackInfo>
 MP4Metadata::GetTrackInfo(mozilla::TrackInfo::TrackType aType,
@@ -253,6 +265,7 @@ MP4Metadata::GetTrackInfo(mozilla::Track
   mozilla::UniquePtr<mozilla::TrackInfo> info =
       mStagefright->GetTrackInfo(aType, aTrackNumber);
 
+#ifdef MOZ_RUST_MP4PARSE
   if (!mRust) {
     return info;
   }
@@ -305,6 +318,7 @@ MP4Metadata::GetTrackInfo(mozilla::Track
   if (mPreferRust) {
     return infoRust;
   }
+#endif // MOZ_RUST_MP4PARSE
 
   return info;
 }
@@ -319,6 +333,7 @@ const CryptoFile&
 MP4Metadata::Crypto() const
 {
   const CryptoFile& crypto = mStagefright->Crypto();
+#ifdef MOZ_RUST_MP4PARSE
   const CryptoFile& rustCrypto = mRust->Crypto();
 
 #ifndef RELEASE_OR_BETA
@@ -330,6 +345,7 @@ MP4Metadata::Crypto() const
   if (mPreferRust) {
     return rustCrypto;
   }
+#endif // MOZ_RUST_MP4PARSE
 
   return crypto;
 }
@@ -594,6 +610,7 @@ MP4MetadataStagefright::Metadata(Stream*
   return parser->Metadata();
 }
 
+#ifdef MOZ_RUST_MP4PARSE
 bool
 RustStreamAdaptor::Read(uint8_t* buffer, uintptr_t size, size_t* bytes_read)
 {
@@ -859,5 +876,6 @@ MP4MetadataRust::Metadata(Stream* aSourc
   MOZ_ASSERT(false, "Not yet implemented");
   return nullptr;
 }
+#endif // MOZ_RUST_MP4PARSE
 
 } // namespace mp4_demuxer
