# $NetBSD: Makefile,v 1.8 2000/10/22 09:22:34 skrll Exp $
#

DISTNAME=	qtarch-2.1-1
PKGNAME=	qtarch-2.1
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	x11 devel
MASTER_SITES=	ftp://qtarch.sourceforge.net/pub/qtarch/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://qtarch.sourceforge.net/

DEPENDS+=	qt2-libs-*:../../x11/qt2-libs
DEPENDS+=	png-*:../../graphics/png

USE_X11=	yes
USE_GMAKE=	yes

EVAL_PREFIX+=	QT2DIR=qt2-libs
MAKE_ENV=	QTDIR=${QT2DIR}/qt2
PATH=		${QTDIR}/bin:$$PATH

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtarch ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/qtarch
	${MKDIR} ${PREFIX}/share/qtarch/help
	${INSTALL_DATA} ${WRKSRC}/help/* ${PREFIX}/share/qtarch/help
	${MKDIR} ${PREFIX}/share/qtarch/doc
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/qtarch/doc

.include "../../mk/bsd.pkg.mk"
