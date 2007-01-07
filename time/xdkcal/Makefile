# $NetBSD: Makefile,v 1.5 2007/01/07 09:14:14 rillig Exp $
#

DISTNAME=	xdkcal-0.9d
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://www.shiratori.riec.tohoku.ac.jp/~jir/linux/products/xdkcal/

MAINTAINER=	mishka@apk.od.ua
HOMEPAGE=	http://www.shiratori.riec.tohoku.ac.jp/~jir/linux/products/xdkcal/index-e.html
COMMENT=	X Desktop Calendar

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdkcal ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xdkcal.1x ${PREFIX}/${PKGMANDIR}/man1/xdkcal.1

.include "../../mk/bsd.pkg.mk"
