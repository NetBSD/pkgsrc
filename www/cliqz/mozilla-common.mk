# $NetBSD: mozilla-common.mk,v 1.9 2020/03/31 15:40:54 fox Exp $
#
# Common Makefile fragment for mozilla packages based on gecko 2.0.
# derived from www/firefox
#
# Customized for Cliqz

UNLIMIT_RESOURCES+=	datasize

.include "../../mk/bsd.prefs.mk"

# For rustc/cargo detection
MOZ_CONFIGURE_ARGS+=	"ac_add_options --target=${MACHINE_GNU_PLATFORM}"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --host=${MACHINE_GNU_PLATFORM}"

CONFIGURE_ENV+=		BINDGEN_CFLAGS="-isystem${PREFIX}/include/nspr \
			-isystem${X11BASE}/include/pixman-1"

.if ${MACHINE_ARCH} == "i386"
# Fix for PR pkg/48152.
CXXFLAGS+=	-march=i586
# This is required for SSE2 code under i386.
CXXFLAGS+=	-mstackrealign
.endif

CHECK_PORTABILITY_SKIP+=	build-tools/scripts/l10n/release_repacks.sh
CHECK_PORTABILITY_SKIP+=	mozilla-release/intl/icu/source/configure
CHECK_PORTABILITY_SKIP+=	mozilla-release/modules/pdfium/update.sh
CHECK_PORTABILITY_SKIP+=	mozilla-release/security/nss/tests/libpkix/libpkix.sh
CHECK_PORTABILITY_SKIP+=	mozilla-release/security/nss/tests/multinit/multinit.sh

# Configure arguments
MOZ_CONFIGURE_ARGS+=	"ac_add_options --disable-crashreporter"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --disable-updater"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --disable-debug"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --disable-debug-symbols"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --disable-tests"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --disable-necko-wifi"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --disable-libjpeg-turbo"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --disable-icf"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --disable-jemalloc"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --disable-webrtc"

MOZ_CONFIGURE_ARGS+=	"ac_add_options --with-system-icu"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --with-system-nss"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --with-system-nspr"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --with-system-zlib"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --with-system-bz2"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --with-system-libvpx"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --with-system-libevent=${BUILDLINK_PREFIX.libevent}"

MOZ_CONFIGURE_ARGS+=	"ac_add_options --enable-default-toolkit=cairo-gtk3"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --enable-system-pixman"
# Disable Rust SIMD option to fix build with lang/rust-1.33.0
# This should be enabled later again.
#MOZ_CONFIGURE_ARGS+=	"ac_add_options --enable-rust-simd"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --enable-system-ffi"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --enable-chrome-format=flat"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --enable-gconf"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --with-libclang-path=${PREFIX}/lib"

# Fix binary path
SUBST_CLASSES+=			prefix
SUBST_STAGE.prefix=		pre-configure
SUBST_MESSAGE.prefix=		Setting PREFIX
SUBST_FILES.prefix+=		${WRKSRC}/mozilla-release/xpcom/build/BinaryPath.h
SUBST_VARS.prefix+=		PREFIX

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=       libevent>=1.1
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
BUILDLINK_API_DEPENDS.nspr+=   nspr>=4.25
.include "../../devel/nspr/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
BUILDLINK_API_DEPENDS.nss+=     nss>=3.50
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libwebp+=	libwebp>=1.0.2
.include "../../graphics/libwebp/buildlink3.mk"
BUILDLINK_API_DEPENDS.libvpx+= libvpx>=1.3.0
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
BUILDLINK_API_DEPENDS.pixman+= pixman>=0.25.2
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
