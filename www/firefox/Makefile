# $NetBSD: Makefile,v 1.134 2013/08/07 12:17:54 ryoon Exp $

FIREFOX_VER=	${MOZ_BRANCH}${MOZ_BRANCH_MINOR}
MOZ_BRANCH=	23.0
MOZ_BRANCH_MINOR=	

DISTNAME=	firefox-${FIREFOX_VER}.source
PKGNAME=	firefox-${MOZ_BRANCH}${MOZ_BRANCH_MINOR:S/b/beta/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/} \
		${MASTER_SITE_MOZILLA_ALL:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

WRKSRC=		${WRKDIR}/mozilla-release

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.mozilla.com/en-US/firefox/
COMMENT=	Web browser with support for extensions
LICENSE=	mpl-1.1

MOZILLA_DIR=	# empty

# Note: when updating remember to conditionalise about-background.png in PLIST
# XXX Firefox 21.0's firefox/xulrunner separation is not working.
CONFIGURE_ARGS+=	--enable-application=browser

# workround for link of libxul.so etc.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/firefox ${COMPILER_RPATH_FLAG}${PREFIX}/lib
LDFLAGS.SunOS+=		-lm

ALL_ENV+=		MOZILLA_PKG_NAME=firefox

.include "../../mk/bsd.prefs.mk"

# Avoid ld "invalid section index" errors.
.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-fdata-sections
BUILDLINK_TRANSFORM+=	rm:-ffunction-sections
.endif

LDFLAGS.DragonFly=	-lplc4 -lnspr4
LDFLAGS.FreeBSD=	-lplc4 -lnspr4
LDFLAGS.Linux=		-lnspr4

.include "../../www/firefox/mozilla-common.mk"
.include "options.mk"

CHECK_INTERPRETER_SKIP+=lib/firefox-sdk/sdk/bin/header.py
CHECK_INTERPRETER_SKIP+=lib/firefox-sdk/sdk/bin/typelib.py
CHECK_INTERPRETER_SKIP+=lib/firefox-sdk/sdk/bin/xpidl.py
CHECK_INTERPRETER_SKIP+=lib/firefox-sdk/sdk/bin/xpt.py

MOZILLA=firefox
MOZILLA_ICON=	${WRKSRC}/dist/firefox/browser/chrome/icons/default/default48.png
.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
MOZILLA_NAME=	Firefox
.else
MOZILLA_NAME=	Browser
.endif

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/js/src && autoconf
# XXX Makefile is broken? When libxul is provided from devel/xulrunner,
# XXX please remove this.
	mkdir ${WRKSRC}/js/src/.deps

post-build:
	${SED} -e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@FIREFOX_ICON@|${MOZILLA}.png|g'			\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop

INSTALLATION_DIRS+=	share/applications share/pixmaps
post-install:
	${INSTALL_DATA} ${WRKDIR}/desktop				\
	  ${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${MOZILLA_ICON}					\
	  ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
