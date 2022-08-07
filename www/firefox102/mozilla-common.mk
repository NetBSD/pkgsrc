# $NetBSD: mozilla-common.mk,v 1.2 2022/08/07 18:08:08 nia Exp $
#
# common Makefile fragment for mozilla packages based on gecko 2.0.
#
# used by www/firefox/Makefile

.include "../../mk/bsd.prefs.mk"

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool
ALL_ENV+=			PYTHON3=${PYTHONBIN}

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_TOOLS+=		pkg-config perl gmake autoconf213 gm4 unzip zip
UNLIMIT_RESOURCES+=	datasize virtualsize

USE_LANGUAGES+=		c c++

# ERROR: Only GCC 7.1 or newer is supported (found version 5.5.0).
GCC_REQD+=		7

TOOL_DEPENDS+=		cbindgen>=0.23.0:../../devel/cbindgen

.if defined(FIREFOX_MAINTAINER) && !defined(MAINTAINER_INTERNAL)
TOOL_DEPENDS+=		nodejs-[0-9]*:../../lang/nodejs
USE_TOOLS+=		diff
.else
CONFIGURE_ENV+=		NODEJS="${FILESDIR}/node-wrapper.sh"
.endif

TOOL_DEPENDS+=		${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
TOOL_DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
TOOL_DEPENDS+=		nasm>=2.14:../../devel/nasm
TOOL_DEPENDS+=		yasm>=1.1:../../devel/yasm
CFLAGS+=		-msse2
.endif

# This is to work around build failures where an upstream configuration script
# is confused by having more than one approximate match to MACHINE_GNU_PLATFORM
# "i486" when attempting to select the Rust compiler target.
.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
CONFIGURE_ARGS+=	--target=i586-unknown-netbsd
CONFIGURE_ARGS+=	--host=i586-unknown-netbsd
.else
CONFIGURE_ARGS+=	--target=${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM}
.endif

CONFIGURE_ENV+=		BINDGEN_CFLAGS="-isystem${PREFIX}/include/nspr \
			-isystem${X11BASE}/include/pixman-1"

do-test:
	cd ${WRKSRC}/${OBJDIR}/dist/bin &&	\
	     ./run-mozilla.sh ${WRKSRC}/mach check-spidermonkey

# tar(1) of OpenBSD 5.5 has no --exclude command line option.
.if ${OPSYS} == "OpenBSD"
TOOLS_PLATFORM.tar=	${TOOLS_PATH.bsdtar}
USE_TOOLS+=		bsdtar
.else
USE_TOOLS+=		tar
.endif

.if ${MACHINE_ARCH} == "i386"
# This is required for SSE2 code under i386.
CXXFLAGS+=	-mstackrealign
.endif

CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}security/nss/tests/*/*.sh
CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}js/src/tests/update-test262.sh
CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}intl/icu/source/configure
CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}browser/components/loop/run-all-loop-tests.sh
CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}browser/extensions/loop/run-all-loop-tests.sh
#CHECK_PORTABILITY_SKIP+=	${MOZILLA_DIR}modules/pdfium/update.sh

CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk3
CONFIGURE_ARGS+=	--enable-release
# Disable Rust SIMD option to fix build with lang/rust-1.33.0
# This should be enabled later again.
#CONFIGURE_ARGS+=	--enable-rust-simd
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
CONFIGURE_ARGS+=	--with-system-libevent
CONFIGURE_ARGS+=	--disable-crashreporter
CONFIGURE_ARGS+=	--enable-chrome-format=omni
CONFIGURE_ARGS+=	--with-system-webp

#CONFIGURE_ARGS+=	--enable-readline
CONFIGURE_ARGS+=	--disable-icf
CONFIGURE_ARGS+=	--disable-updater

.include "../../mk/compiler.mk"

.if empty(PKGSRC_COMPILER:Mclang)
# Set path to "clang for cbindgen" when target compiler is not clang.
CONFIGURE_ARGS+=	--with-clang-path=${PREFIX}/bin/clang
.endif
CONFIGURE_ARGS+=	--with-libclang-path=${PREFIX}/lib

# RLBox WASM sandbox
.if ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "i386"
# For wasm-ld command
BUILD_DEPENDS+=		lld-[0-9]*:../../devel/lld
.include "../../lang/wasi-libc/buildlink3.mk"
.include "../../lang/wasi-libcxx/buildlink3.mk"
# NB the exact versions of the clang and wasi-compiler-rt dependencies must
# be kept in sync, or build failures will occur due to path mismatches.
.include "../../lang/wasi-compiler-rt/buildlink3.mk"
CONFIGURE_ARGS+=	--with-wasi-sysroot=${PREFIX}/wasi
CONFIGURE_ENV+=		WASM_CC=${PREFIX}/bin/clang
CONFIGURE_ENV+=		WASM_CXX=${PREFIX}/bin/clang++
.else
CONFIGURE_ARGS+=	--without-wasm-sandboxed-libraries
.endif

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths+=		${MOZILLA_DIR}xpcom/io/nsAppFileLocationProvider.cpp
SUBST_SED.fix-paths+=		-e 's,/usr/lib/mozilla/plugins,${PREFIX}/lib/netscape/plugins,g'

.include "../../sysutils/pciutils/libname.mk"
SUBST_CLASSES+=				fix-libpci-soname
SUBST_STAGE.fix-libpci-soname=		pre-configure
SUBST_MESSAGE.fix-libpci-soname=	Fixing libpci soname
SUBST_FILES.fix-libpci-soname+=		${MOZILLA_DIR}toolkit/xre/glxtest.cpp
SUBST_SED.fix-libpci-soname+=		-e 's,"libpci.so, "lib${PCIUTILS_LIBNAME}.so,'

# Workaround for link of libxul.so as of 96.0.
# There are too many -ldl under third_paty/libwebrtc.
BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl

CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}js/src/build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}nsprpub/build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}/js/ctypes/libffi/config.guess
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}js/src/build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}nsprpub/build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}/js/ctypes/libffi/config.sub

CONFIGURE_ENV+=		CPP=${CPP:Q}
ALL_ENV+=		SHELL=${CONFIG_SHELL:Q}

# Build outside ${WRKSRC}
# Try to avoid conflict with config/makefiles/xpidl/Makefile.in
.if ${MAINTAINER_INTERNAL:Uno} == "yes"
OBJDIR=			../no-node-build
.else
OBJDIR=			../build
.endif
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

PLIST_VARS+=	ffvpx

.if ${MACHINE_ARCH} == "aarch64" || \
    ${MACHINE_ARCH:M*arm*} || \
    ${MACHINE_ARCH} == "i386" || \
    ${MACHINE_ARCH} == "x86_64"
PLIST.ffvpx=	yes	# see media/ffvpx/ffvpxcommon.mozbuild
.endif

# See ${WRKSRC}/security/sandbox/mac/Sandbox.mm: On Darwin, sandboxing
# support is only available when the toolkit is cairo-cocoa.
CONFIGURE_ARGS.Darwin+=	--disable-sandbox

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

.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../mk/atomic64.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=1.1
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.34
.include "../../devel/nspr/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
BUILDLINK_API_DEPENDS.nss+=	nss>=3.79
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
#.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
#BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.10.2nb4
#.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.libwebp+=	libwebp>=1.0.2
.include "../../graphics/libwebp/buildlink3.mk"
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
RUST_REQ=	1.59.0
.include "../../lang/rust/rust.mk"
# webrtc option requires internal libvpx
#BUILDLINK_API_DEPENDS.libvpx+=	libvpx>=1.3.0
#.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
# textproc/hunspell 1.3 is too old
#.include "../../textproc/hunspell/buildlink3.mk"
.include "../../multimedia/ffmpeg5/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
BUILDLINK_API_DEPENDS.pixman+= pixman>=0.25.2
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
PLIST_VARS+=		wayland
.if ${PKG_BUILD_OPTIONS.gtk3:Mwayland}
PLIST.wayland=		yes
.endif
.include "../../lang/python/pyversion.mk"
