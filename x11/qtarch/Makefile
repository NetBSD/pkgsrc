# $NetBSD: Makefile,v 1.24 2004/10/03 00:18:38 tv Exp $
#

DISTNAME=	qtarch-2.2-1
PKGNAME=	qtarch-2.2
PKGREVISION=	1
CATEGORIES=	x11 devel
#MASTER_SITES=	ftp://qtarch.sourceforge.net/pub/qtarch/
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qtarch/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://qtarch.sourceforge.net/
COMMENT=	Graphical dialog editor for the Qt widget set

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=	yes
USE_X11=	yes
USE_GNU_TOOLS+=	make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtarch ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/qtarch
	${INSTALL_DATA_DIR} ${PREFIX}/share/qtarch/help
	${INSTALL_DATA} ${WRKSRC}/help/* ${PREFIX}/share/qtarch/help
	${INSTALL_DATA_DIR} ${PREFIX}/share/qtarch/doc
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/qtarch/doc

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/qt2-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
