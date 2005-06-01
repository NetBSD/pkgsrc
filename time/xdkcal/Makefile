# $NetBSD: Makefile,v 1.3 2005/06/01 18:03:24 jlam Exp $
#

DISTNAME=	xdkcal-0.9d
CATEGORIES=	time
MASTER_SITES=	http://www.shiratori.riec.tohoku.ac.jp/~jir/linux/products/xdkcal/

MAINTAINER=	mishka@apk.od.ua
HOMEPAGE=	http://www.shiratori.riec.tohoku.ac.jp/~jir/linux/products/xdkcal/index-e.html
COMMENT=	X Desktop Calendar

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin man/man1

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdkcal ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xdkcal.1x ${PREFIX}/man/man1/xdkcal.1

.include "../../mk/bsd.pkg.mk"
