# $NetBSD: Makefile,v 1.20 2004/01/20 12:28:27 agc Exp $
#

DISTNAME=	qtarch-2.1-1
PKGNAME=	qtarch-2.1
PKGREVISION=	1
CATEGORIES=	x11 devel
MASTER_SITES=	ftp://qtarch.sourceforge.net/pub/qtarch/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://qtarch.sourceforge.net/
COMMENT=	Graphical dialog editor for the Qt widget set

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK2=	yes
USE_X11=	yes
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtarch ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/qtarch
	${INSTALL_DATA_DIR} ${PREFIX}/share/qtarch/help
	${INSTALL_DATA} ${WRKSRC}/help/* ${PREFIX}/share/qtarch/help
	${INSTALL_DATA_DIR} ${PREFIX}/share/qtarch/doc
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/qtarch/doc

.include "../../graphics/png/buildlink2.mk"
.include "../../x11/qt2-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
