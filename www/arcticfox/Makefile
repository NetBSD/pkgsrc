# $NetBSD: Makefile,v 1.52 2024/10/20 14:04:42 wiz Exp $

DISTNAME=	arcticfox-45.1
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=rmottola/}
GITHUB_PROJECT=	Arctic-Fox
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/rmottola/Arctic-Fox
COMMENT=	Web browser for aging systems, forked from Firefox
LICENSE=	mpl-1.1

USE_TOOLS+=	perl pkg-config autoconf213
USE_TOOLS+=	zip unzip gmake

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CONFIG_GUESS_OVERRIDE+=	./build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=	./intl/icu/source/config.guess
CONFIG_GUESS_OVERRIDE+=	./ipc/chromium/src/third_party/libevent/config.guess
CONFIG_GUESS_OVERRIDE+=	./js/src/ctypes/libffi/config.guess
CONFIG_GUESS_OVERRIDE+=	./memory/jemalloc/src/config.guess
CONFIG_GUESS_OVERRIDE+=	./modules/freetype2/builds/unix/config.guess
CONFIG_GUESS_OVERRIDE+=	./nsprpub/build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=	./toolkit/crashreporter/google-breakpad/autotools/config.guess

CONFIG_SUB_OVERRIDE+=	./build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=	./intl/icu/source/config.sub
CONFIG_SUB_OVERRIDE+=	./ipc/chromium/src/third_party/libevent/config.sub
CONFIG_SUB_OVERRIDE+=	./js/src/ctypes/libffi/config.sub
CONFIG_SUB_OVERRIDE+=	./memory/jemalloc/src/config.sub
CONFIG_SUB_OVERRIDE+=	./modules/freetype2/builds/unix/config.sub
CONFIG_SUB_OVERRIDE+=	./nsprpub/build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=	./toolkit/crashreporter/google-breakpad/autotools/config.sub

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--disable-crashreporter
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-updater
CONFIGURE_ARGS+=	--disable-mozril-geoloc
CONFIGURE_ARGS+=	--disable-webrtc
CONFIGURE_ARGS+=	--disable-safe-browsing
CONFIGURE_ARGS+=	--disable-parental-controls
CONFIGURE_ARGS+=	--disable-safe-browsing
CONFIGURE_ARGS+=	--disable-necko-wifi
CONFIGURE_ARGS+=	--disable-eme
CONFIGURE_ARGS+=	--disable-gamepad
CONFIGURE_ARGS+=	--disable-gio
CONFIGURE_ARGS+=	--enable-install-strip
CONFIGURE_ARGS+=	--enable-release
CONFIGURE_ARGS+=	--enable-strip
CONFIGURE_ARGS+=	--enable-application=browser
CONFIGURE_ARGS+=	--with-branding=browser/branding/arcticfox

# gtk3 now supported and default, but gtk2 less buggy
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk2

# Necessary for PaX safety on NetBSD.
CONFIGURE_ARGS+=	--disable-precompiled-startupcache

CONFIGURE_ARGS+=	--with-system-bz2
CONFIGURE_ARGS+=	--with-system-zlib

.if ${MACHINE_ARCH} == "alpha" || ${MACHINE_ARCH} == "sparc64"
# Without this NetBSD/sparc64 starts, but crashes on some sites
SSP_SUPPORTED=		no
.endif

.include "../../mk/bsd.prefs.mk"

# it thinks yasm is required on arm
.if !${MACHINE_PLATFORM:MNetBSD-*-powerpc*}
TOOL_DEPENDS+=		yasm>=1.1:../../devel/yasm
.endif

CONFIGURE_DIRS=		${WRKDIR}/build
CONFIGURE_SCRIPT=	${WRKSRC}/configure

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGNAME_NOREV}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib

.if ${MACHINE_PLATFORM:MNetBSD-*-earm*}
LDFLAGS+=		-Wl,--no-keep-memory
.endif

CWRAPPERS_APPEND.cc+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGNAME_NOREV}
CWRAPPERS_APPEND.cxx+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGNAME_NOREV}
CWRAPPERS_APPEND.ld+=	${LINKER_RPATH_FLAG}${PREFIX}/lib/${PKGNAME_NOREV}

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/16x16/apps
INSTALLATION_DIRS+=	share/icons/hicolor/32x32/apps
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps
INSTALLATION_DIRS+=	share/icons/hicolor/128x128/apps

CHECK_PORTABILITY_SKIP+=	browser/extensions/loop/*.sh
CHECK_PORTABILITY_SKIP+=	js/src/tests/*.sh
CHECK_PORTABILITY_SKIP+=	memory/jemalloc/src/configure
CHECK_PORTABILITY_SKIP+=	security/nss/tests/*/*.sh

REPLACE_PYTHON+=		xpcom/idl-parser/xpidl/xpidl.py
REPLACE_PYTHON+=		xpcom/typelib/xpt/tools/xpt.py

PYTHON_VERSIONS_ACCEPTED=	27
PYTHON_FOR_BUILD_ONLY=		tool

pre-configure:
	${MKDIR} ${CONFIGURE_DIRS}
	cd ${WRKSRC} && autoconf-2.13
	cd ${WRKSRC}/js/src && autoconf-2.13
	${CP} ${FILESDIR}/cubeb_sun.c ${WRKSRC}/media/libcubeb/src

post-install:
	${FIND} ${DESTDIR}${PREFIX} -name '*.a' -exec ${RM} '{}' ';'
	${RM} -rf ${DESTDIR}${PREFIX}/include
	${RM} -rf ${DESTDIR}${PREFIX}/share/idl
	${INSTALL_DATA} ${WRKSRC}/browser/branding/arcticfox/default16.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/16x16/apps/arcticfox.png
	${INSTALL_DATA} ${WRKSRC}/browser/branding/arcticfox/default32.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/32x32/apps/arcticfox.png
	${INSTALL_DATA} ${WRKSRC}/browser/branding/arcticfox/default48.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps/arcticfox.png
	${INSTALL_DATA} ${WRKSRC}/browser/branding/arcticfox/mozicon128.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/128x128/apps/arcticfox.png
	${INSTALL_DATA} ${FILESDIR}/arcticfox.desktop \
	    ${DESTDIR}${PREFIX}/share/applications/arcticfox.desktop

.include "options.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
