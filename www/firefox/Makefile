# $NetBSD: Makefile,v 1.56 2009/09/16 19:06:18 tnn Exp $
#

DISTNAME=	firefox-${FIREFOX_VER}.source
PKGNAME=	firefox-${FIREFOX_VER}
FIREFOX_VER=	3.5.3
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.mozilla.com/en-US/firefox/
COMMENT=	Web browser with support for extensions

WRKSRC=		${WRKDIR}/mozilla-1.9.1
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config perl gmake autoconf213
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=		zip>=2.3:../../archivers/zip

PKG_DESTDIR_SUPPORT=	user-destdir
CHECK_PORTABILITY_SKIP=	security/nss/tests/libpkix/libpkix.sh

PRIVILEGED_STAGES=	clean

CONFIG_GUESS_OVERRIDE=	build/autoconf/config.guess
CONFIG_SUB_OVERRIDE=	build/autoconf/config.sub

CONFIGURE_ARGS+=	--enable-application=browser
CONFIGURE_ARGS+=	--disable-tests --disable-pedantic
CONFIGURE_ARGS+=	--enable-crypto
CONFIGURE_ARGS+=	--enable-optimize=-O2 --with-pthreads
CONFIGURE_ARGS+=	--disable-javaxpcom
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk2
CONFIGURE_ARGS+=	--enable-svg --enable-mathml
CONFIGURE_ARGS+=	--enable-system-cairo
CONFIGURE_ARGS+=	--with-system-jpeg
CONFIGURE_ARGS+=	--with-system-zlib --with-system-bz2
CONFIGURE_ARGS+=	--enable-system-sqlite
CONFIGURE_ARGS+=	--disable-crashreporter
CONFIGURE_ARGS+=	--with-libxul-sdk=${PREFIX}/lib/xulrunner-sdk

ALL_ENV+=		MOZILLA_PKG_NAME=firefox

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

MOZILLA=firefox
.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
MOZILLA_NAME=	Firefox 3.5
MOZILLA_ICON=	${WRKSRC}/other-licenses/branding/firefox/default48.png
.else
MOZILLA_NAME=	Shiretoko 3.5
MOZILLA_ICON=	${WRKSRC}/browser/branding/unofficial/default48.png
.endif

pre-configure:
	cd ${WRKSRC} && autoconf
# Makefiles sometimes call "rm -f" without more arguments. Kludge around ...
	printf '#!/bin/sh\n[ "$$*" = "-f" ] && exit 0\nexec /bin/rm $$@\n' > \
	  ${WRAPPER_DIR}/bin/rm
	chmod +x ${WRAPPER_DIR}/bin/rm

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/pixmaps
	${SED}	-e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@FIREFOX_ICON@|${MOZILLA}.png|g'			\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop
	${INSTALL_DATA} ${WRKDIR}/desktop				\
	  ${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${MOZILLA_ICON}					\
	  ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png
	rm -f ${DESTDIR}${PREFIX}/bin/firefox
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${FILESDIR}/firefox.sh.in	\
	  > ${WRKDIR}/firefox
	${INSTALL_SCRIPT} ${WRKDIR}/firefox ${DESTDIR}${PREFIX}/bin

.if ${OPSYS} == "Linux"
# XXX check if this still applies after xulrunnerization
.include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
bUILDLINK_API_DEPENDS.xulrunner+=	xulrunner>=1.9.1.3nb4
.include "../../devel/xulrunner/buildlink3.mk"
PLIST_VARS+=	gnome
.if !empty(PKG_BUILD_OPTIONS.xulrunner:Mgnome)
CONFIGURE_ARGS+=	--enable-gnomevfs --enable-dbus --enable-gnomeui
PLIST.gnome=	yes
.else
CONFIGURE_ARGS+=	--disable-gnomevfs --disable-dbus --disable-gnomeui
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
