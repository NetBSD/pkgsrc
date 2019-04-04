# $NetBSD: Makefile,v 1.2 2019/04/04 02:24:40 jmmv Exp $

DISTNAME=	skhd-0.3.2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=koekeishiya/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Simple hotkey daemon for macOS
LICENSE=	mit

ONLY_FOR_PLATFORM=	Darwin-*-*

USE_LANGUAGES=		c99
USE_TOOLS=		gmake
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	examples/com.koekeishiya.skhd.plist
SUBST_SED.paths=	-e 's,/usr/local,${PREFIX},g'

CONF_FILES=	${PREFIX}/share/skhd/com.koekeishiya.skhd.plist \
		/Library/LaunchAgents/com.koekeishiya.skhd.plist

do-build:
	cd ${WRKSRC} && gmake BUILD_FLAGS="-std=c99 -O3"

INSTALLATION_DIRS=	bin share/skhd share/examples/skhd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/skhd \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/examples/skhdrc \
	    ${DESTDIR}${PREFIX}/share/examples/skhd
	${INSTALL_DATA} ${WRKSRC}/examples/com.koekeishiya.skhd.plist \
	    ${DESTDIR}${PREFIX}/share/skhd

.include "../../mk/bsd.pkg.mk"
