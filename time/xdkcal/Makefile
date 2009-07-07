# $NetBSD: Makefile,v 1.8 2009/07/07 19:46:58 joerg Exp $
#

DISTNAME=	xdkcal-0.9d
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://www.shiratori.riec.tohoku.ac.jp/~jir/linux/products/xdkcal/

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.shiratori.riec.tohoku.ac.jp/~jir/linux/products/xdkcal/index-e.html
COMMENT=	X Desktop Calendar

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdkcal ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xdkcal.1x ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xdkcal.1

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
