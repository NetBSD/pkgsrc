$NetBSD: patch-media_libstagefright_binding_MP4Metadata.cpp,v 1.2 2017/08/10 14:46:15 ryoon Exp $

--- media/libstagefright/binding/MP4Metadata.cpp.orig	2017-07-31 16:20:49.000000000 +0000
+++ media/libstagefright/binding/MP4Metadata.cpp
@@ -20,14 +20,18 @@
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
 using mozilla::media::TimeUnit;
@@ -105,6 +109,7 @@ private:
   bool mCanSeek;
 };
 
+#ifdef MOZ_RUST_MP4PARSE
 // Wrap an mp4_demuxer::Stream to remember the read offset.
 
 class RustStreamAdaptor {
@@ -151,6 +156,7 @@ private:
   RustStreamAdaptor mRustSource;
   mozilla::UniquePtr<mp4parse_parser, FreeMP4Parser> mRustParser;
 };
+#endif // MOZ_RUST_MP4PARSE
 
 class IndiceWrapperStagefright : public IndiceWrapper {
 public:
@@ -187,6 +193,7 @@ IndiceWrapperStagefright::GetIndice(size
   return true;
 }
 
+#ifdef MOZ_RUST_MP4PARSE
 // the owner of mIndice is rust mp4 paser, so lifetime of this class
 // SHOULD NOT longer than rust parser.
 class IndiceWrapperRust : public IndiceWrapper
@@ -232,9 +239,11 @@ IndiceWrapperRust::GetIndice(size_t aInd
   aIndice.sync = indice->sync;
   return true;
 }
+#endif // MOZ_RUST_MP4PARSE
 
 MP4Metadata::MP4Metadata(Stream* aSource)
  : mStagefright(MakeUnique<MP4MetadataStagefright>(aSource))
+#ifdef MOZ_RUST_MP4PARSE
  , mRust(MakeUnique<MP4MetadataRust>(aSource))
  , mPreferRust(MediaPrefs::EnableRustMP4Parser())
  , mReportedAudioTrackTelemetry(false)
@@ -242,6 +251,7 @@ MP4Metadata::MP4Metadata(Stream* aSource
 #ifndef RELEASE_OR_BETA
  , mRustTestMode(MediaPrefs::RustTestMode())
 #endif
+#endif // MOZ_RUST_MP4PARSE
 {
 }
 
@@ -274,8 +284,11 @@ MP4Metadata::GetNumberTracks(mozilla::Tr
   MP4Metadata::ResultAndTrackCount numTracks =
     mStagefright->GetNumberTracks(aType);
 
+#ifdef MOZ_RUST_MP4PARSE
   if (!mRust) {
+#endif // MOZ_RUST_MP4PARSE
     return numTracks;
+#ifdef MOZ_RUST_MP4PARSE
   }
 
   MP4Metadata::ResultAndTrackCount numTracksRust =
@@ -350,8 +363,10 @@ MP4Metadata::GetNumberTracks(mozilla::Tr
   // Same non-error numbers, just return any.
   // (Choosing Rust here, in case it carries a warning, we'd want to know that.)
   return numTracksRust;
+#endif // MOZ_RUST_MP4PARSE
 }
 
+#ifdef MOZ_RUST_MP4PARSE
 bool MP4Metadata::ShouldPreferRust() const {
   if (!mRust) {
     return false;
@@ -389,6 +404,7 @@ bool MP4Metadata::ShouldPreferRust() con
   // Otherwise, fall back.
   return false;
 }
+#endif // MOZ_RUST_MP4PARSE
 
 static const char*
 GetDifferentField(const mozilla::TrackInfo& info,
@@ -443,6 +459,7 @@ MP4Metadata::GetTrackInfo(mozilla::Track
   MP4Metadata::ResultAndTrackInfo info =
     mStagefright->GetTrackInfo(aType, aTrackNumber);
 
+#ifdef MOZ_RUST_MP4PARSE
   if (!mRust) {
     return info;
   }
@@ -514,6 +531,7 @@ MP4Metadata::GetTrackInfo(mozilla::Track
   if (mPreferRust) {
     return infoRust;
   }
+#endif // MOZ_RUST_MP4PARSE
 
   return info;
 }
@@ -528,6 +546,7 @@ MP4Metadata::ResultAndCryptoFile
 MP4Metadata::Crypto() const
 {
   MP4Metadata::ResultAndCryptoFile crypto = mStagefright->Crypto();
+#ifdef MOZ_RUST_MP4PARSE
   MP4Metadata::ResultAndCryptoFile rustCrypto = mRust->Crypto();
 
 #ifndef RELEASE_OR_BETA
@@ -548,6 +567,7 @@ MP4Metadata::Crypto() const
   if (mPreferRust) {
     return rustCrypto;
   }
+#endif // MOZ_RUST_MP4PARSE
 
   return crypto;
 }
@@ -556,17 +576,22 @@ MP4Metadata::ResultAndIndice
 MP4Metadata::GetTrackIndice(mozilla::TrackID aTrackID)
 {
   FallibleTArray<Index::Indice> indiceSF;
+#ifdef MOZ_RUST_MP4PARSE
   if (!mPreferRust
 #ifndef RELEASE_OR_BETA
       || mRustTestMode
 #endif
      ) {
+#endif // MOZ_RUST_MP4PARSE
     MediaResult rv = mStagefright->ReadTrackIndex(indiceSF, aTrackID);
     if (NS_FAILED(rv)) {
       return {Move(rv), nullptr};
     }
+#ifdef MOZ_RUST_MP4PARSE
   }
+#endif // MOZ_RUST_MP4PARSE
 
+#ifdef MOZ_RUST_MP4PARSE
   mp4parse_byte_data indiceRust = {};
   if (mPreferRust
 #ifndef RELEASE_OR_BETA
@@ -592,13 +617,18 @@ MP4Metadata::GetTrackIndice(mozilla::Tra
     }
   }
 #endif
+#endif // MOZ_RUST_MP4PARSE
 
   UniquePtr<IndiceWrapper> indice;
+#ifdef MOZ_RUST_MP4PARSE
   if (mPreferRust) {
     indice = mozilla::MakeUnique<IndiceWrapperRust>(indiceRust);
   } else {
+#endif // MOZ_RUST_MP4PARSE
     indice = mozilla::MakeUnique<IndiceWrapperStagefright>(indiceSF);
+#ifdef MOZ_RUST_MP4PARSE
   }
+#endif // MOZ_RUST_MP4PARSE
 
   return {NS_OK, Move(indice)};
 }
@@ -856,6 +886,7 @@ MP4MetadataStagefright::Metadata(Stream*
   return {NS_OK, Move(buffer)};
 }
 
+#ifdef MOZ_RUST_MP4PARSE
 bool
 RustStreamAdaptor::Read(uint8_t* buffer, uintptr_t size, size_t* bytes_read)
 {
@@ -1152,5 +1183,6 @@ MP4MetadataRust::Metadata(Stream* aSourc
   MOZ_ASSERT(false, "Not yet implemented");
   return {NS_ERROR_NOT_IMPLEMENTED, nullptr};
 }
+#endif // MOZ_RUST_MP4PARSE
 
 } // namespace mp4_demuxer
