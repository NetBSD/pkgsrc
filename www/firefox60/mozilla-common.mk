# $NetBSD: mozilla-common.mk,v 1.9 2020/03/30 19:46:02 joerg Exp $
#
# common Makefile fragment for mozilla packages based on gecko 2.0.
#
# used by www/firefox60/Makefile

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_TOOLS+=		pkg-config perl gmake autoconf213 unzip zip
USE_LANGUAGES+=		c99 c++
UNLIMIT_RESOURCES+=	datasize virtualsize

GCC_REQD+=		4.9

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=		yasm>=1.1:../../devel/yasm

# Enable Google widevine CDM. This requires external libwidevinecdm.so.
#CONFIGURE_ARGS+=	--enable-eme=widevine
.endif

# For rustc/cargo detection
CONFIGURE_ARGS+=	--target=${MACHINE_GNU_PLATFORM:Q}
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM:Q}

CONFIGURE_ENV+=		BINDGEN_CFLAGS="-isystem${PREFIX}/include/nspr \
			-isystem${X11BASE}/include/pixman-1"
# with files/*.rs for Rust 1.39.0
CONFIGURE_ARGS+=	--disable-stylo-build-bindgen

test:
	cd ${WRKSRC}/${OBJDIR}/dist/bin &&	\
	     ./run-mozilla.sh ${WRKSRC}/mach check-spidermonkey

# tar(1) of OpenBSD 5.5 has no --exclude command line option.
.if ${OPSYS} == "OpenBSD"
TOOLS_PLATFORM.tar=	${TOOLS_PATH.bsdtar}
USE_TOOLS+=		bsdtar
.endif
.if ${MACHINE_ARCH} == "i386"
# Fix for PR pkg/48152.
CXXFLAGS+=		-march=i586
# This is required for SSE2 code under i386.
CXXFLAGS+=		-mstackrealign
.endif

CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}security/nss/tests/libpkix/libpkix.sh
CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}security/nss/tests/multinit/multinit.sh
CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}js/src/tests/update-test262.sh
CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}intl/icu/source/configure
CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}browser/components/loop/run-all-loop-tests.sh
CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}browser/extensions/loop/run-all-loop-tests.sh

CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk3
.if ${OPSYS} != "SunOS"
CONFIGURE_ARGS+=	--enable-pie
.endif
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--with-pthreads
# Mozilla Bug 1432751
#CONFIGURE_ARGS+=	--enable-system-cairo
CONFIGURE_ARGS+=	--enable-system-pixman
# too new to build with webrtc?
#CONFIGURE_ARGS+=	--with-system-libvpx
# textproc/hunspell 1.3 is too old
#CONFIGURE_ARGS+=	--enable-system-hunspell
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
#CONFIGURE_ARGS+=	--disable-libjpeg-turbo

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

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Fixing path to python.
SUBST_FILES.python+=	media/webrtc/trunk/build/common.gypi
SUBST_SED.python+=	-e 's,<!(python,<!(${PYTHONBIN},'

# Build outside ${WRKSRC}
# Try to avoid conflict with config/makefiles/xpidl/Makefile.in
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

PLIST_VARS+=	sps vorbis tremor glskia throwwrapper mozglue avx86

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "little"
PLIST.glskia=	yes
.endif

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PLIST.avx86=	yes	# see media/libav/README_MOZILLA: only used on x86
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
BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.18
.include "../../devel/nspr/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
BUILDLINK_API_DEPENDS.nss+=	nss>=3.35
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
#.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
#BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.10.2nb4
#.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
BUILDLINK_API_DEPENDS.rust+=	rust>=1.23.0
BUILDLINK_DEPMETHOD.rust=	build
.include "../../lang/rust/buildlink3.mk"
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
