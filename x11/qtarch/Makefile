# $NetBSD: Makefile,v 1.3 2000/07/11 14:53:47 agc Exp $
#

DISTNAME=	qtarch-2.0-1
PKGNAME=	qtarch-2.0
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	x11 devel
MASTER_SITES=	http://www.qtarch.intranova.net/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.qtarch.intranova.net/

DEPENDS+=	qt2-*:../../x11/qt
DEPENDS+=	png-*:../../graphics/png

USE_X11=	yes
USE_GMAKE=	yes

MAKE_ENV=	QTDIR=`${MAKE} show-qt2-prefix`/qt2
PATH=		${QTDIR}/bin:$$PATH

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtarch ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/qtarch
	${MKDIR} ${PREFIX}/share/qtarch/help
	${INSTALL_DATA} ${WRKSRC}/help/* ${PREFIX}/share/qtarch/help
	${MKDIR} ${PREFIX}/share/qtarch/doc
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/qtarch/doc

.include "../../mk/bsd.pkg.mk"
