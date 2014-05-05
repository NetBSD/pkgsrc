# $NetBSD: Makefile,v 1.24 2014/05/05 00:48:26 ryoon Exp $

.include "../../devel/xulrunner17/dist.mk"
PKGNAME=	firefox17-${MOZ_BRANCH}
PKGREVISION=	4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozilla.com/en-US/firefox/
COMMENT=	Web browser with support for extensions (version 17.x)
LICENSE=	mpl-1.1

MOZILLA_DIR=	# empty

# Note: when updating remember to conditionalise about-background.png in PLIST
CONFIGURE_ARGS+=	--enable-application=browser
CONFIGURE_ARGS+=	--with-libxul-sdk=${PREFIX}/lib/xulrunner17
CONFIGURE_ARGS+=	--with-system-libxul

ALL_ENV+=		MOZILLA_PKG_NAME=firefox17

LDFLAGS.DragonFly=	-lplc4 -lnspr4
LDFLAGS.FreeBSD=	-lplc4 -lnspr4
LDFLAGS.Linux=		-lnspr4

.include "../../devel/xulrunner17/mozilla-common.mk"
.include "options.mk"

MOZILLA=firefox17
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
	  > ${WRKDIR}/firefox

INSTALLATION_DIRS+=	share/applications share/pixmaps
post-install:
	${INSTALL_DATA} ${WRKDIR}/desktop				\
	  ${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${MOZILLA_ICON}					\
	  ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png
	rm -f ${DESTDIR}${PREFIX}/bin/firefox17
	${INSTALL_SCRIPT} ${WRKDIR}/firefox ${DESTDIR}${PREFIX}/bin/firefox17

BUILDLINK_API_DEPENDS.xulrunner17+=	xulrunner17>=${MOZ_BRANCH}
BUILD_DEPENDS+=				xulrunner17-${MOZ_BRANCH}{,nb*}:../../devel/xulrunner17
.include "../../devel/xulrunner17/buildlink3.mk"
PLIST_VARS+=	gnome
.if !empty(PKG_BUILD_OPTIONS.xulrunner17:Mgnome)
CONFIGURE_ARGS+=	--enable-gnomevfs --enable-dbus --enable-gnomeui
PLIST.gnome=	yes
.else
CONFIGURE_ARGS+=	--disable-gnomevfs --disable-dbus --disable-gnomeui
.endif
.if !empty(PKG_BUILD_OPTIONS.xulrunner17:Mdebug)
CONFIGURE_ARGS+=	--enable-debug --enable-debug-symbols
CONFIGURE_ARGS+=	--disable-install-strip
.else
CONFIGURE_ARGS+=	--disable-debug --disable-debug-symbols
CONFIGURE_ARGS+=	--enable-install-strip
.endif
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
