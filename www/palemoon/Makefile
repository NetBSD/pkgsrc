# $NetBSD: Makefile,v 1.10 2024/09/15 06:15:43 nia Exp $
# for build instructions see
# https://developer.palemoon.org/build/linux/

PKGNAME=	palemoon-33.3.1
CATEGORIES=	www

DIST_SUBDIR=	palemoon-${PKGVERSION_NOREV}
DISTFILES+=	palemoon.tar.gz
DISTFILES+=	uxp.tar.gz
DISTFILES+=	psutil.tar.gz

SITES.palemoon.tar.gz= \
	-https://repo.palemoon.org/MoonchildProductions/Pale-Moon/archive/${PKGVERSION_NOREV}_Release.tar.gz

SITES.uxp.tar.gz= \
	-https://repo.palemoon.org/MoonchildProductions/UXP/archive/RB_20240909.tar.gz

SITES.psutil.tar.gz= \
	-https://files.pythonhosted.org/packages/7b/58/2675697b6831e6ac4b7b7bc4e5dcdb24a2f39f8411186573eb0de16eb6d5/psutil-3.4.2.tar.gz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://repo.palemoon.org/MoonchildProductions/Pale-Moon
COMMENT=	Customizable web browser (unofficial distribution of Pale Moon)
LICENSE=	mpl-2.0

USE_TOOLS+=	perl pkg-config autoconf213
USE_TOOLS+=	zip unzip gmake

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++17

WRKSRC=		${WRKDIR}/pale-moon

CONFIG_GUESS_OVERRIDE+=	platform/build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=	platform/intl/icu/source/config.guess
CONFIG_GUESS_OVERRIDE+=	platform/ipc/chromium/src/third_party/libevent/config.guess
CONFIG_GUESS_OVERRIDE+=	platform/js/src/ctypes/libffi/config.guess
CONFIG_GUESS_OVERRIDE+=	platform/nsprpub/build/autoconf/config.guess

CONFIG_SUB_OVERRIDE+=	platform/build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=	platform/intl/icu/source/config.sub
CONFIG_SUB_OVERRIDE+=	platform/ipc/chromium/src/third_party/libevent/config.sub
CONFIG_SUB_OVERRIDE+=	platform/js/src/ctypes/libffi/config.sub
CONFIG_SUB_OVERRIDE+=	platform/nsprpub/build/autoconf/config.sub

CONFIGURE_DIRS=		${WRKDIR}/build
CONFIGURE_SCRIPT=	${WRKSRC}/configure

# recommended flags from upstream
CONFIGURE_ARGS+=	--enable-application=palemoon
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk2
CONFIGURE_ARGS+=	--enable-devtools
CONFIGURE_ARGS+=	--enable-av1
CONFIGURE_ARGS+=	--enable-jxl
CONFIGURE_ARGS+=	--disable-webrtc
CONFIGURE_ARGS+=	--disable-gamepad
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-necko-wifi
CONFIGURE_ARGS+=	--disable-updater
CONFIGURE_ARGS+=	--with-pthreads

# non-default: upstream is very strict about trademark usage
CONFIGURE_ARGS+=	--with-branding=palemoon/branding/unofficial

# non-default: causes build failures on NetBSD
CONFIGURE_ARGS+=	--disable-precompiled-startupcache

# non-default: do not override system memory allocator
CONFIGURE_ARGS+=	--disable-jemalloc

# non-default options to integrate better with pkgsrc
# do not use system cairo, causes segfaults
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-optimize=-O2
CONFIGURE_ARGS+=	--with-system-bz2
CONFIGURE_ARGS+=	--with-system-zlib

CWRAPPERS_APPEND.cc+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGNAME_NOREV}
CWRAPPERS_APPEND.cxx+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGNAME_NOREV}
CWRAPPERS_APPEND.ld+=	${LINKER_RPATH_FLAG}${PREFIX}/lib/${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
TOOL_DEPENDS+=		yasm>=1.1:../../devel/yasm
.endif

.if ${MACHINE_PLATFORM:MNetBSD-*-earm*}
LDFLAGS+=		-Wl,--no-keep-memory
.endif

PLIST_VARS+=		ffvpx

.if ${MACHINE_ARCH} == "x86_64"
PLIST.ffvpx=		yes	# see platform/old-configure.in
.endif

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/16x16/apps
INSTALLATION_DIRS+=	share/icons/hicolor/32x32/apps
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps
INSTALLATION_DIRS+=	share/icons/hicolor/128x128/apps

CHECK_PORTABILITY_SKIP+=	platform/js/src/tests/*.sh
CHECK_PORTABILITY_SKIP+=	platform/memory/jemalloc/src/configure
CHECK_PORTABILITY_SKIP+=	platform/security/nss/tests/*/*.sh

PYTHON_VERSIONS_ACCEPTED=	27
PYTHON_FOR_BUILD_ONLY=		tool

pre-configure:
	${MKDIR} ${CONFIGURE_DIRS}
	cd ${WRKSRC} && autoconf-2.13
	cd ${WRKSRC}/palemoon && autoconf-2.13
	cd ${WRKSRC}/platform/js/src && autoconf-2.13

pre-patch:
	${MV} ${WRKDIR}/uxp/* ${WRKSRC}/platform/
	${RM} -rf ${WRKSRC}/platform/python/psutil
	${MV} ${WRKDIR}/psutil-3.4.2 ${WRKSRC}/platform/python/psutil

pre-build:
	${TOUCH} ${WRKSRC}/platform/configure
	${TOUCH} ${WRKDIR}/build/config.status

post-install:
	${FIND} ${DESTDIR}${PREFIX} -name '*.a' -exec ${RM} '{}' ';'
	${RM} -rf ${DESTDIR}${PREFIX}/include
	${RM} -rf ${DESTDIR}${PREFIX}/share/idl
	${RM} -rf ${DESTDIR}${PREFIX}/lib/palemoon-devel-${PKGVERSION_NOREV}
	${INSTALL_DATA} ${WRKSRC}/palemoon/branding/unofficial/default16.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/16x16/apps/palemoon.png
	${INSTALL_DATA} ${WRKSRC}/palemoon/branding/unofficial/default32.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/32x32/apps/palemoon.png
	${INSTALL_DATA} ${WRKSRC}/palemoon/branding/unofficial/default48.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps/palemoon.png
	${INSTALL_DATA} ${WRKSRC}/palemoon/branding/unofficial/mozicon128.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/128x128/apps/palemoon.png
	${INSTALL_DATA} ${WRKSRC}/palemoon/branding/unofficial/browser.desktop \
	    ${DESTDIR}${PREFIX}/share/applications/palemoon.desktop

.include "options.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
