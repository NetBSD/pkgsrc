# $NetBSD: Makefile,v 1.4 2000/03/28 00:12:31 dmcmahill Exp $

DISTNAME=	QwSpriteField1.6
PKGNAME=	qwspritefield-1.6
CATEGORIES=	x11 graphics
MASTER_SITES=	ftp://ftp.troll.no/contrib/

MAINTAINER=	packages@netbsd.org

DEPENDS+=	qt1-1.44:../../x11/qt1

CONFLICTS=	kdesupport-1.0

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/QwSpriteField

QW_INCLUDES=	Pix.h QwCluster.h QwPublicList.h QwSpriteField.h

PATH=		${X11BASE}/qt1/bin:$$PATH

MAKE_ENV+=	"QTDIR=${X11BASE}/qt1"

do-install:
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/libQwSpriteField.la \
	  ${PREFIX}/lib
.for FILE in ${QW_INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/qt1/include
.endfor

.include "../../mk/bsd.pkg.mk"
