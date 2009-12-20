# $NetBSD: Makefile,v 1.59.2.2 2009/12/20 19:41:08 spz Exp $
#

DISTNAME=	firefox-${FIREFOX_VER}.source
PKGNAME=	firefox-${FIREFOX_VER}
FIREFOX_VER=	3.5.6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.mozilla.com/en-US/firefox/
COMMENT=	Web browser with support for extensions

WRKSRC=		${WRKDIR}/mozilla-1.9.1
MOZILLA_DIR=	# empty

CONFIGURE_ARGS+=	--enable-application=browser
CONFIGURE_ARGS+=	--with-libxul-sdk=${PREFIX}/lib/xulrunner-sdk
CONFIGURE_ARGS+=	--with-system-libxul

ALL_ENV+=		MOZILLA_PKG_NAME=firefox

DISTINFO_FILE=		${.CURDIR}/../../devel/xulrunner/distinfo
PATCHDIR=		${.CURDIR}/../../devel/xulrunner/patches

.include "../../devel/xulrunner/mozilla-common.mk"
.include "options.mk"

MOZILLA=firefox
.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
MOZILLA_NAME=	Firefox 3.5
MOZILLA_ICON=	${WRKSRC}/other-licenses/branding/firefox/default48.png
.else
MOZILLA_NAME=	Browser 3.5
MOZILLA_ICON=	${WRKSRC}/browser/branding/unofficial/default48.png
.endif

pre-configure:
	cd ${WRKSRC} && autoconf

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

BUILDLINK_API_DEPENDS.xulrunner+=	xulrunner-1.9.1.6{,nb*}
.include "../../devel/xulrunner/buildlink3.mk"
PLIST_VARS+=	gnome
.if !empty(PKG_BUILD_OPTIONS.xulrunner:Mgnome)
CONFIGURE_ARGS+=	--enable-gnomevfs --enable-dbus --enable-gnomeui
PLIST.gnome=	yes
.else
CONFIGURE_ARGS+=	--disable-gnomevfs --disable-dbus --disable-gnomeui
.endif
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
