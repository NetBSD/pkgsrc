# $NetBSD: Makefile,v 1.11 2022/07/02 16:53:37 ryoon Exp $

DISTNAME=	arcticfox-39.1
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=wicknix/}
GITHUB_PROJECT=	Arctic-Fox
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wicknix/Arctic-Fox
COMMENT=	Web browser for aging systems, forked from Firefox
LICENSE=	mpl-1.1

USE_TOOLS+=	perl pkg-config autoconf213
USE_TOOLS+=	zip unzip gmake

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--disable-crashreporter
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-updater
CONFIGURE_ARGS+=	--disable-mozril-geoloc
CONFIGURE_ARGS+=	--disable-webrtc
CONFIGURE_ARGS+=	--disable-safe-browsing
CONFIGURE_ARGS+=	--disable-parental-controls
CONFIGURE_ARGS+=	--enable-release
CONFIGURE_ARGS+=	--disable-necko-wifi
CONFIGURE_ARGS+=	--disable-eme
CONFIGURE_ARGS+=	--disable-gamepad
CONFIGURE_ARGS+=	--disable-gio
CONFIGURE_ARGS+=	--enable-strip
CONFIGURE_ARGS+=	--enable-install-strip
CONFIGURE_ARGS+=	--enable-application=browser
CONFIGURE_ARGS+=	--with-branding=browser/branding/arcticfox

# Necessary for PaX safety on NetBSD.
CONFIGURE_ARGS+=	--disable-precompiled-startupcache

CONFIGURE_ARGS+=	--enable-system-cairo
CONFIGURE_ARGS+=	--enable-system-pixman
CONFIGURE_ARGS+=	--enable-system-hunspell
CONFIGURE_ARGS+=	--enable-system-ffi
CONFIGURE_ARGS+=	--with-system-bz2
# Needs libjpeg-turbo.
# CONFIGURE_ARGS+=	--with-system-jpeg
# Causes build failures. :-/
# CONFIGURE_ARGS+=	--with-system-icu
CONFIGURE_ARGS+=	--with-system-libevent=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=	--with-system-libvpx
CONFIGURE_ARGS+=	--with-system-nss
CONFIGURE_ARGS+=	--with-system-nspr
CONFIGURE_ARGS+=	--with-system-zlib

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
TOOL_DEPENDS+=		yasm>=1.1:../../devel/yasm
.endif

PLIST_VARS+=	skia
.if ${MACHINE_ARCH} != "powerpc"
PLIST.skia=	yes
.endif

CONFIGURE_DIRS=		${WRKDIR}/build
CONFIGURE_SCRIPT=	${WRKSRC}/configure

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGNAME_NOREV}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/16x16/apps
INSTALLATION_DIRS+=	share/icons/hicolor/32x32/apps
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps
INSTALLATION_DIRS+=	share/icons/hicolor/128x128/apps

CHECK_PORTABILITY_SKIP+=	intl/icu/source/configure
CHECK_PORTABILITY_SKIP+=	js/src/tests/*.sh
CHECK_PORTABILITY_SKIP+=	memory/jemalloc/src/configure
CHECK_PORTABILITY_SKIP+=	security/nss/tests/*/*.sh

REPLACE_PYTHON+=		xpcom/idl-parser/xpidl/xpidl.py
REPLACE_PYTHON+=		xpcom/typelib/xpt/tools/xpt.py

PYTHON_VERSIONS_ACCEPTED=	27
TOOL_DEPENDS+=			${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

NOT_PAX_MPROTECT_SAFE+=		lib/${PKGNAME_NOREV}/arcticfox
NOT_PAX_MPROTECT_SAFE+=		lib/${PKGNAME_NOREV}/arcticfox-bin

pre-configure:
	${MKDIR} ${CONFIGURE_DIRS}
	cd ${WRKSRC} && autoconf-2.13
	cd ${WRKSRC}/js/src && autoconf-2.13
	${CP} ${FILESDIR}/cubeb_sun.c ${WRKSRC}/media/libcubeb/src

post-install:
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
.include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=1.1
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/hunspell/buildlink3.mk"
#.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
#.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
