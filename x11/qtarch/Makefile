# $NetBSD: Makefile,v 1.28 2005/06/17 03:50:44 jlam Exp $
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
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

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
