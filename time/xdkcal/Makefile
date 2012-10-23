# $NetBSD: Makefile,v 1.10 2012/10/23 10:24:12 wiz Exp $
#

DISTNAME=	xdkcal-0.9d
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://www.shiratori.riec.tohoku.ac.jp/~jir/linux/products/xdkcal/

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.shiratori.riec.tohoku.ac.jp/~jir/linux/products/xdkcal/index-e.html
COMMENT=	X Desktop Calendar

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdkcal ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xdkcal.1x ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xdkcal.1

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
