# $NetBSD: Makefile,v 1.13 2001/09/27 23:19:02 jlam Exp $
#

DISTNAME=	qtarch-2.1-1
PKGNAME=	qtarch-2.1
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	x11 devel
MASTER_SITES=	ftp://qtarch.sourceforge.net/pub/qtarch/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://qtarch.sourceforge.net/
COMMENT=	Graphical dialog editor for the Qt widget set

DEPENDS+=	qt2-libs-[0-9]*:../../x11/qt2-libs
DEPENDS+=	png>=1.0.11:../../graphics/png

USE_X11=	yes
USE_GMAKE=	yes

EVAL_PREFIX+=	QT2DIR=qt2-libs
MAKE_ENV=	QTDIR=${QT2DIR}/qt2
PATH=		${QTDIR}/bin:$$PATH

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtarch ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/qtarch
	${INSTALL_DATA_DIR} ${PREFIX}/share/qtarch/help
	${INSTALL_DATA} ${WRKSRC}/help/* ${PREFIX}/share/qtarch/help
	${INSTALL_DATA_DIR} ${PREFIX}/share/qtarch/doc
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/qtarch/doc

.include "../../mk/bsd.pkg.mk"
