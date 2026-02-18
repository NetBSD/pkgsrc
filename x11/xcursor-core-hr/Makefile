# $NetBSD: Makefile,v 1.6 2026/02/18 08:03:33 wiz Exp $

DISTNAME=	xc-core-hr
PKGVER=		20241226
PKGNAME=	xcursor-core-hr-${PKGVER}
CATEGORIES=	x11 graphics
MASTER_SITES=	https://fastestcode.org/dl/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alx210/xc-core-hr
COMMENT=	High-resolution version of X11 core cursor theme
LICENSE=	cc-by-sa-v3.0

USE_LANGUAGES=	# none
USE_TOOLS+=	pax
ICON_THEMES=	yes

TOOL_DEPENDS+=	xcursorgen>=1.0.5:../../x11/xcursorgen

INSTALLATION_DIRS+=	share/icons

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} ./build.sh

do-install:
	cd ${WRKSRC} && ${PAX} -wr core-hr					\
	${DESTDIR}${PREFIX}/share/icons

post-install:
	${INSTALL_DATA} ${FILESDIR}/index.theme					\
	${DESTDIR}${PREFIX}/share/icons/core-hr

.include "../../mk/bsd.pkg.mk"
