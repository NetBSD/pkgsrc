# $NetBSD: Makefile,v 1.1 2026/11/24 11:09:39 nia Exp $

DISTNAME=	mocu-xcursor-1.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=sevmeyer/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sevmeyer/mocu-xcursor
COMMENT=	Modest xcursor theme
LICENSE=	cc0-1.0-universal

NO_BUILD=	yes
ICON_THEMES=	yes

WRKSRC=		${WRKDIR}

do-install:
.for dir in Mocu-Black-Left Mocu-White-Left \
    Mocu-Black-Right Mocu-White-Right
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/index.theme \
	    ${DESTDIR}${PREFIX}/share/icons/${dir}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/${dir}/cursors
	${INSTALL_DATA} ${WRKSRC}/${dir}/cursors/* \
	    ${DESTDIR}${PREFIX}/share/icons/${dir}/cursors
.endfor

.include "../../mk/bsd.pkg.mk"
