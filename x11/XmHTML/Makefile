# $NetBSD: Makefile,v 1.21 2001/05/22 09:32:27 wiz Exp $
#

DISTNAME=       XmHTML-1.1.7
CATEGORIES=	x11
MASTER_SITES=   http://www.xs4all.nl/~ripley/XmHTML/dist/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://www.xs4all.nl/~ripley/XmHTML/
COMMENT=	Motif Widget capable of displaying HTML 3.2 conforming text

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.11:../../graphics/png

USE_X11=	YES
USE_XPM=	YES
USE_MOTIF=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES

NO_CONFIGURE=	YES

MAKE_ENV+=	CC="${CC}"

do-install:
	${LIBTOOL} ${LIBTOOL_FLAGS} ${INSTALL_DATA} \
		${WRKSRC}/lib/libXmHTML.la ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/XmHTML
	${INSTALL_DATA} ${WRKSRC}/include/XmHTML/*.h ${PREFIX}/include/XmHTML

.include "../../mk/bsd.pkg.mk"
