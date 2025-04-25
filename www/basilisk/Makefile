# $NetBSD: Makefile,v 1.1 2025/04/25 21:25:03 nia Exp $
# This package is mostly derived from www/palemoon since they use the
# same backend.  However, several key things are different.

PKGNAME=	basilisk-2025.04.23
CATEGORIES=	www

DIST_SUBDIR=	basilisk-${PKGVERSION_NOREV}
DISTFILES+=	basilisk.tar.gz
DISTFILES+=	uxp.tar.gz
DISTFILES+=	psutil.tar.gz

SITES.basilisk.tar.gz= \
	-https://repo.palemoon.org/Basilisk-Dev/Basilisk/archive/v${PKGVERSION_NOREV}.tar.gz

SITES.uxp.tar.gz= \
	-https://repo.palemoon.org/MoonchildProductions/UXP/archive/d892468fd052cb8961b7e36d5b087e53eb625f8e.tar.gz

SITES.psutil.tar.gz= \
	-https://files.pythonhosted.org/packages/7b/58/2675697b6831e6ac4b7b7bc4e5dcdb24a2f39f8411186573eb0de16eb6d5/psutil-3.4.2.tar.gz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.basilisk-browser.org/
COMMENT=	UXP-based web browser inspired by pre-Servo Firefox
LICENSE=	mpl-2.0

USE_TOOLS+=	perl pkg-config autoconf213
USE_TOOLS+=	zip unzip gmake

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++

# "ERROR: Only GCC 9.1 or newer is supported"
# Use GCC 10 because 9 is untested.
GCC_REQD+=	10

WRKSRC=		${WRKDIR}/basilisk

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/basilisk-52.9.0

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

# see basilisk/mozconfigs/linux/x86_64/gtk3_unofficial_branding.mozconfig
CONFIGURE_ARGS+=	--enable-optimize=-O3
CONFIGURE_ARGS+=	--enable-application=basilisk
CONFIGURE_ARGS+=	--enable-devtools
CONFIGURE_ARGS+=	--enable-av1
CONFIGURE_ARGS+=	--enable-jxl
CONFIGURE_ARGS+=	--enable-pie
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--disable-gamepad	# non-default
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-necko-wifi
CONFIGURE_ARGS+=	--disable-updater
CONFIGURE_ARGS+=	--with-pthreads
CONFIGURE_ARGS+=	--disable-gconf
# unlike palemoon/firefox, basilisk *only* has "unofficial branding"
CONFIGURE_ARGS+=	--disable-official-branding

# non-default: causes build failures on NetBSD
CONFIGURE_ARGS+=	--disable-precompiled-startupcache

# non-default: do not override system memory allocator
CONFIGURE_ARGS+=	--disable-jemalloc

# non-default options to integrate better with pkgsrc
# do not use system cairo, causes segfaults
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-system-bz2=${BUILDLINK_PREFIX.bzip2}
CONFIGURE_ARGS+=	--with-system-zlib

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

SUBST_CLASSES+=		desktop
SUBST_STAGE.desktop=	pre-configure
SUBST_FILES.desktop=	platform/toolkit/mozapps/installer/linux/rpm/mozilla.desktop
SUBST_SED.desktop=	-e 's,@MOZ_APP_DISPLAYNAME@,Basilisk,g'
SUBST_SED.desktop+=	-e 's,@MOZ_APP_NAME@,basilisk,g'

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
	cd ${WRKSRC}/basilisk && autoconf-2.13
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
	${RM} -rf ${DESTDIR}${PREFIX}/lib/*-devel*
	${RM} -rf ${DESTDIR}${PREFIX}/lib/basilisk-devel-${PKGVERSION_NOREV}
	${INSTALL_DATA} ${WRKSRC}/basilisk/branding/unofficial/default16.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/16x16/apps/basilisk.png
	${INSTALL_DATA} ${WRKSRC}/basilisk/branding/unofficial/default32.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/32x32/apps/basilisk.png
	${INSTALL_DATA} ${WRKSRC}/basilisk/branding/unofficial/default48.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps/basilisk.png
	${INSTALL_DATA} ${WRKSRC}/basilisk/branding/unofficial/mozicon128.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/128x128/apps/basilisk.png
	${INSTALL_DATA} ${WRKSRC}/platform/toolkit/mozapps/installer/linux/rpm/mozilla.desktop \
	    ${DESTDIR}${PREFIX}/share/applications/basilisk.desktop

.include "options.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-cocoa
.else
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk3
.  include "../../x11/gtk2/buildlink3.mk"
.  include "../../x11/gtk3/buildlink3.mk"
.  include "../../x11/libXt/buildlink3.mk"
.endif
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
