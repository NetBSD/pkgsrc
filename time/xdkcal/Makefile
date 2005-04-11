# $NetBSD: Makefile,v 1.2 2005/04/11 21:47:45 tv Exp $
#

DISTNAME=	xdkcal-0.9d
CATEGORIES=	time
MASTER_SITES=	http://www.shiratori.riec.tohoku.ac.jp/~jir/linux/products/xdkcal/

MAINTAINER=	mishka@apk.od.ua
HOMEPAGE=	http://www.shiratori.riec.tohoku.ac.jp/~jir/linux/products/xdkcal/index-e.html
COMMENT=	X Desktop Calendar

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_X11=		yes

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdkcal ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xdkcal.1x ${PREFIX}/man/man1/xdkcal.1

.include "../../mk/bsd.pkg.mk"
