# $NetBSD: Makefile,v 1.21 2013/12/30 00:24:07 dholland Exp $

.include "../../devel/xulrunner10/dist.mk"
PKGNAME=	firefox10-${FIREFOX_VER}
PKGREVISION=	9
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/en-US/firefox/organizations/
COMMENT=	Web browser with support for extensions (version 10.x)
LICENSE=	mpl-1.1

MOZILLA_DIR=	# empty

CONFIGURE_ARGS+=	--enable-application=browser
CONFIGURE_ARGS+=	--with-libxul-sdk=${PREFIX}/lib/xulrunner10-sdk
CONFIGURE_ARGS+=	--with-system-libxul

ALL_ENV+=		MOZILLA_PKG_NAME=firefox10

LDFLAGS.DragonFly=	-lplc4 -lnspr4

.include "../../devel/xulrunner10/mozilla-common.mk"
.include "options.mk"

MOZILLA=firefox10
MOZILLA_ICON=	${WRKSRC}/dist/firefox/chrome/icons/default/default48.png
.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
MOZILLA_NAME=	Firefox
.else
MOZILLA_NAME=	Browser
.endif

pre-configure:
	cd ${WRKSRC} && autoconf
# XXX not built here, just to make check-portability.awk shut up.
	cd ${WRKSRC}/js/src && autoconf

post-build:
	${SED} -e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@FIREFOX_ICON@|${MOZILLA}.png|g'			\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${FILESDIR}/firefox.sh.in	\
	  > ${WRKDIR}/${MOZILLA}

INSTALLATION_DIRS+=	share/applications share/pixmaps
post-install:
	${INSTALL_DATA} ${WRKDIR}/desktop				\
	  ${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${MOZILLA_ICON}					\
	  ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png
	rm -f ${DESTDIR}${PREFIX}/bin/firefox10
	${INSTALL_SCRIPT} ${WRKDIR}/${MOZILLA} ${DESTDIR}${PREFIX}/bin

BUILDLINK_API_DEPENDS.xulrunner10+=	xulrunner10>=${MOZ_BRANCH}${MOZ_BRANCH_MINOR}
BUILD_DEPENDS+=				xulrunner10-${MOZ_BRANCH}${MOZ_BRANCH_MINOR}{,nb*}:../../devel/xulrunner10
.include "../../devel/xulrunner10/buildlink3.mk"
PLIST_VARS+=	gnome
.if !empty(PKG_BUILD_OPTIONS.xulrunner10:Mgnome)
CONFIGURE_ARGS+=	--enable-gnomevfs --enable-dbus --enable-gnomeui
PLIST.gnome=	yes
.else
CONFIGURE_ARGS+=	--disable-gnomevfs --disable-dbus --disable-gnomeui
.endif
.if !empty(PKG_BUILD_OPTIONS.xulrunner10:Mdebug)
CONFIGURE_ARGS+=	--enable-debug --enable-debug-symbols
CONFIGURE_ARGS+=	--disable-install-strip
.else
CONFIGURE_ARGS+=	--disable-debug --disable-debug-symbols
CONFIGURE_ARGS+=	--enable-install-strip
.endif
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
