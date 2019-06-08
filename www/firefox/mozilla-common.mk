# $NetBSD: mozilla-common.mk,v 1.134 2019/06/08 11:46:02 ryoon Exp $
#
# common Makefile fragment for mozilla packages based on gecko 2.0.
#
# used by www/firefox/Makefile

.include "../../mk/bsd.prefs.mk"

# Python 2.7 and Python 3.6 or later are required simultaneously.
PYTHON_VERSIONS_ACCEPTED=	27
PYTHON_FOR_BUILD_ONLY=		tool
.if !empty(PYTHON_VERSION_DEFAULT:M37) || !empty(PYTHON_VERSION_DEFAULT:M36)
TOOL_DEPENDS+=		python${PYTHON_VERSION_DEFAULT}-[0-9]*:../../lang/python${PYTHON_VERSION_DEFAULT}
ALL_ENV+=	PYTHON3=${LOCALBASE}/bin/python${PYTHON_VERSION_DEFAULT:S/3/3./}
.else
TOOL_DEPENDS+=		python37-[0-9]*:../../lang/python37
ALL_ENV+=	PYTHON3=${LOCALBASE}/bin/python3.7
.endif

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_TOOLS+=		pkg-config perl gmake autoconf213 unzip zip
USE_LANGUAGES+=		c99 gnu++14
UNLIMIT_RESOURCES+=	datasize

TOOL_DEPENDS+=		cbindgen>=0.6.8:../../devel/cbindgen
.if ${MACHINE_ARCH} == "sparc64"
CONFIGURE_ARGS+=	--disable-nodejs
.else
TOOL_DEPENDS+=		nodejs-[0-9]*:../../lang/nodejs
.endif

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=		nasm>=1.1:../../devel/nasm
BUILD_DEPENDS+=		yasm>=1.1:../../devel/yasm
.endif

# For rustc/cargo detection
CONFIGURE_ARGS+=	--target=${MACHINE_GNU_PLATFORM:Q}
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM:Q}

CONFIGURE_ENV+=		BINDGEN_CFLAGS="-isystem${PREFIX}/include/nspr \
			-isystem${X11BASE}/include/pixman-1"

test:
	cd ${WRKSRC}/${OBJDIR}/dist/bin &&	\
	     ./run-mozilla.sh ${WRKSRC}/mach check-spidermonkey

# tar(1) of OpenBSD 5.5 has no --exclude command line option.
.if ${OPSYS} == "OpenBSD"
TOOLS_PLATFORM.tar=	${TOOLS_PATH.bsdtar}
USE_TOOLS+=		bsdtar
.endif
GCC_REQD+=		6.1
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-7]**-*) || \
	!empty(MACHINE_PLATFORM:MNetBSD-8.[0-8]*-*)
USE_PKGSRC_GCC_RUNTIME=	yes
.endif
.if ${MACHINE_ARCH} == "i386"
# Fix for PR pkg/48152.
CXXFLAGS+=		-march=i586
# This is required for SSE2 code under i386.
CXXFLAGS+=		-mstackrealign
.endif

CXXFLAGS+=		-D__HAVE_INLINE___ISINF

CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}security/nss/tests/libpkix/libpkix.sh
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}security/nss/tests/multinit/multinit.sh
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}js/src/tests/update-test262.sh
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}intl/icu/source/configure
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}browser/components/loop/run-all-loop-tests.sh
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}browser/extensions/loop/run-all-loop-tests.sh
#CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}modules/pdfium/update.sh

CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk3
CONFIGURE_ARGS+=	--enable-release
# Disable Rust SIMD option to fix build with lang/rust-1.33.0
# This should be enabled later again.
#CONFIGURE_ARGS+=	--enable-rust-simd
CONFIGURE_ARGS+=	--enable-webrender=build
CONFIGURE_ARGS+=	--disable-tests
# Mozilla Bug 1432751
#CONFIGURE_ARGS+=	--enable-system-cairo
CONFIGURE_ARGS+=	--enable-system-pixman
# webrtc option requires internal libvpx
#CONFIGURE_ARGS+=	--with-system-libvpx
CONFIGURE_ARGS+=	--enable-system-ffi
CONFIGURE_ARGS+=	--with-system-icu
CONFIGURE_ARGS+=	--with-system-nss
CONFIGURE_ARGS+=	--with-system-nspr
#CONFIGURE_ARGS+=	--with-system-jpeg
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-system-bz2
CONFIGURE_ARGS+=	--with-system-libevent=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=	--disable-crashreporter
CONFIGURE_ARGS+=	--disable-necko-wifi
CONFIGURE_ARGS+=	--enable-chrome-format=flat
CONFIGURE_ARGS+=	--disable-libjpeg-turbo
CONFIGURE_ARGS+=	--with-system-webp

CONFIGURE_ARGS+=	--disable-gconf
#CONFIGURE_ARGS+=	--enable-readline
CONFIGURE_ARGS+=	--disable-icf
CONFIGURE_ARGS+=	--disable-updater

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths+=		${MOZILLA_DIR}xpcom/io/nsAppFileLocationProvider.cpp
SUBST_SED.fix-paths+=		-e 's,/usr/lib/mozilla/plugins,${PREFIX}/lib/netscape/plugins,g'

SUBST_CLASSES+=			prefix
SUBST_STAGE.prefix=		pre-configure
SUBST_MESSAGE.prefix=		Setting PREFIX
SUBST_FILES.prefix+=		${MOZILLA_DIR}xpcom/build/BinaryPath.h
SUBST_VARS.prefix+=		PREFIX

CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}js/src/build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}nsprpub/build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}/js/ctypes/libffi/config.guess
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}js/src/build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}nsprpub/build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}/js/ctypes/libffi/config.sub

CONFIGURE_ENV+=		CPP=${CPP}

# Build outside ${WRKSRC}
# Try to avoid conflict with config/makefiles/xpidl/Makefile.in
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

PLIST_VARS+=	sps vorbis tremor glskia throwwrapper mozglue ffvpx

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "little"
PLIST.glskia=	yes
.endif

.if ${MACHINE_ARCH} == "aarch64" || \
    !empty(MACHINE_ARCH:M*arm*) || \
    ${MACHINE_ARCH} == "i386" || \
    ${MACHINE_ARCH} == "x86_64"
PLIST.ffvpx=	yes	# see media/ffvpx/ffvpxcommon.mozbuild
.endif

.if ${MACHINE_ARCH} != "sparc64"
# For some reasons the configure test for GCC bug 26905 still triggers on
# sparc64, which makes mozilla skip the installation of a few wrapper headers.
# Other archs end up with one additional file in the SDK headers
PLIST.throwwrapper=	yes
.endif

.if !empty(MACHINE_PLATFORM:S/i386/x86/:MLinux-*-x86*)
PLIST.sps=	yes
.endif

.if !empty(MACHINE_PLATFORM:MLinux-*-arm*)
PLIST.tremor=	yes
.else
PLIST.vorbis=	yes
.endif

# See ${WRKSRC}/mozglue/build/moz.build: libmozglue is built and
# installed as a shared library on these platforms.
.if ${OPSYS} == "Cygwin" || ${OPSYS} == "Darwin" # or Android
PLIST.mozglue=	yes
.endif

# See ${WRKSRC}/security/sandbox/mac/Sandbox.mm: On Darwin, sandboxing
# support is only available when the toolkit is cairo-cocoa.
CONFIGURE_ARGS.Darwin+=	--disable-sandbox

# See ${WRKSRC}/configure.in: It tries to use MacOS X 10.6 SDK by
# default, which is not always possible.
.if !empty(MACHINE_PLATFORM:MDarwin-8.*-*)
CONFIGURE_ARGS+=	--enable-macos-target=10.4
.elif !empty(MACHINE_PLATFORM:MDarwin-9.*-*)
CONFIGURE_ARGS+=	--enable-macos-target=10.5
.endif

# Makefiles sometimes call "rm -f" without more arguments. Kludge around ...
.PHONY: create-rm-wrapper
pre-configure: create-rm-wrapper
create-rm-wrapper:
	printf '#!/bin/sh\n[ "$$*" = "-f" ] && exit 0\nexec /bin/rm $$@\n' > \
	  ${WRAPPER_DIR}/bin/rm
	chmod +x ${WRAPPER_DIR}/bin/rm

# The configure test for __thread succeeds, but later we end up with:
# dist/bin/libxul.so: undefined reference to `__tls_get_addr'
CONFIGURE_ENV.NetBSD+=	ac_cv_thread_keyword=no
# In unspecified case, clock_gettime(CLOCK_MONOTONIC, ...) fails.
CONFIGURE_ENV.NetBSD+=	ac_cv_clock_monotonic=

.if ${OPSYS} == "SunOS"
# native libbz2.so hides BZ2_crc32Table
PREFER.bzip2?=	pkgsrc
.endif

.if ${OPSYS} == "OpenBSD"
PLIST_SUBST+=	DLL_SUFFIX=".so.1.0"
.elif ${OPSYS} == "Darwin"
PLIST_SUBST+=	DLL_SUFFIX=".dylib"
.else
PLIST_SUBST+=	DLL_SUFFIX=".so"
.endif

.include "../../archivers/bzip2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=1.1
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.21
.include "../../devel/nspr/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
BUILDLINK_API_DEPENDS.nss+=	nss>=3.40.1
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
#.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
#BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.10.2nb4
#.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.libwebp+=	libwebp>=1.0.2
.include "../../graphics/libwebp/buildlink3.mk"
BUILDLINK_DEPMETHOD.clang=	build
BUILDLINK_API_DEPENDS.clang+=	clang>=6.0.1nb1
.include "../../lang/clang/buildlink3.mk"
BUILDLINK_DEPMETHOD.rust=	build
BUILDLINK_API_DEPENDS.rust+=	rust>=1.31.0
.include "../../lang/rust/buildlink3.mk"
# webrtc option requires internal libvpx
#BUILDLINK_API_DEPENDS.libvpx+=	libvpx>=1.3.0
#.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
# textproc/hunspell 1.3 is too old
#.include "../../textproc/hunspell/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
BUILDLINK_API_DEPENDS.pixman+= pixman>=0.25.2
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
