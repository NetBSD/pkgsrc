# $NetBSD: Makefile,v 1.26.2.1 2002/06/30 06:24:37 jlam Exp $
#

DISTNAME=       XmHTML-1.1.7
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=   http://www.xs4all.nl/~ripley/XmHTML/dist/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://www.xs4all.nl/~ripley/XmHTML/
COMMENT=	Motif Widget capable of displaying HTML 3.2 conforming text

USE_X11BASE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES
USE_BUILDLINK2=	YES

do-install:
	${LIBTOOL} ${LIBTOOL_FLAGS} ${INSTALL_DATA} \
		${WRKSRC}/lib/libXmHTML.la ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/XmHTML
	${INSTALL_DATA} ${WRKSRC}/include/XmHTML/*.h ${PREFIX}/include/XmHTML

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
