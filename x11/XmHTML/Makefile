# $NetBSD: Makefile,v 1.15 2000/06/21 06:25:36 jlam Exp $
#

DISTNAME=       XmHTML-1.1.7
CATEGORIES=	x11
MASTER_SITES=   http://www.xs4all.nl/~ripley/XmHTML/dist/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://www.xs4all.nl/~ripley/XmHTML/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.6:../../graphics/png

USE_X11=	# defined
USE_MOTIF=	# defined
USE_GMAKE=	# defined
USE_LIBTOOL=	# defined

NO_CONFIGURE=	# defined

do-install:
	${LIBTOOL} ${LIBTOOL_FLAGS} ${INSTALL_DATA} \
		${WRKSRC}/lib/libXmHTML.la ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/XmHTML
	${INSTALL_DATA} ${WRKSRC}/include/XmHTML/*.h ${PREFIX}/include/XmHTML

.include "../../mk/bsd.pkg.mk"
