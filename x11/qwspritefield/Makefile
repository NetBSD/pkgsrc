# $NetBSD: Makefile,v 1.1.1.1 1999/03/23 21:08:01 tron Exp $

DISTNAME=	QwSpriteField1.6
PKGNAME=	qwspritefield-1.6
CATEGORIES=	x11 graphics
MASTER_SITES=	ftp://ftp.troll.no/contrib/

MAINTAINER=	tron@netbsd.org

DEPENDS+=	qt-1.42:../../x11/qt

CONFLICTS=	kdesupport-1.0

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/QwSpriteField

QW_INCLUDES=	Pix.h QwCluster.h QwPublicList.h QwSpriteField.h

do-install:
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/libQwSpriteField.la \
	  ${PREFIX}/lib
.for FILE in ${QW_INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/include/qt
.endfor

.include "../../mk/bsd.pkg.mk"
