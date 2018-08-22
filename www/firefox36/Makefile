# $NetBSD: Makefile,v 1.55 2018/08/22 09:47:24 wiz Exp $

.include "../../devel/xulrunner192/dist.mk"
PKGNAME=	firefox36-${FIREFOX_VER}
PKGREVISION=	38
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozilla.com/en-US/firefox/
COMMENT=	Web browser with support for extensions (version 3.6.x)
LICENSE=	mpl-1.1

MOZILLA_DIR=	# empty

CONFIGURE_ARGS+=	--enable-application=browser
CONFIGURE_ARGS+=	--with-libxul-sdk=${PREFIX}/lib/xulrunner192-sdk
CONFIGURE_ARGS+=	--with-system-libxul

ALL_ENV+=		MOZILLA_PKG_NAME=firefox36

SUBST_CLASSES+=			fix-paths2
SUBST_STAGE.fix-paths2=		pre-configure
SUBST_MESSAGE.fix-paths2=	Fixing absolute paths.
SUBST_FILES.fix-paths2=		${MOZILLA_DIR}xpcom/build/nsXPCOMPrivate.h
SUBST_FILES.fix-paths2+=	${MOZILLA_DIR}xulrunner/app/nsRegisterGREUnix.cpp
SUBST_FILES.fix-paths2+=	${MOZILLA_DIR}xulrunner/installer/Makefile.in
SUBST_SED.fix-paths2=		-e 's,/etc/gre.d,${PREFIX}/lib/xulrunner192/gre.d,g'

.include "../../devel/xulrunner192/mozilla-common.mk"
CONFIGURE_ARGS+=		--enable-chrome-format=jar
.include "options.mk"

MOZILLA=firefox36
.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
MOZILLA_NAME=	Firefox 3.6
MOZILLA_ICON=	${WRKSRC}/other-licenses/branding/firefox/default48.png
.else
MOZILLA_NAME=	Browser 3.6
MOZILLA_ICON=	${WRKSRC}/browser/branding/unofficial/default48.png
.endif

pre-configure:
	cd ${WRKSRC} && autoconf

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
	rm -f ${DESTDIR}${PREFIX}/bin/${MOZILLA}
	${INSTALL_SCRIPT} ${WRKDIR}/${MOZILLA} ${DESTDIR}${PREFIX}/bin

BUILDLINK_API_DEPENDS.xulrunner192+=	xulrunner192>=${MOZ_BRANCH}${MOZ_BRANCH_MINOR}
BUILD_DEPENDS+=				xulrunner192-${MOZ_BRANCH}${MOZ_BRANCH_MINOR}{,nb*}:../../devel/xulrunner192
.include "../../devel/xulrunner192/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.xulrunner192:Mgnome)
CONFIGURE_ARGS+=	--enable-gnomevfs --enable-dbus --enable-gnomeui
.else
CONFIGURE_ARGS+=	--disable-gnomevfs --disable-dbus --disable-gnomeui
.endif
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
