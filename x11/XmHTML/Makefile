# $NetBSD: Makefile,v 1.23 2001/10/23 13:15:07 jlam Exp $
#

DISTNAME=       XmHTML-1.1.7
CATEGORIES=	x11
MASTER_SITES=   http://www.xs4all.nl/~ripley/XmHTML/dist/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://www.xs4all.nl/~ripley/XmHTML/
COMMENT=	Motif Widget capable of displaying HTML 3.2 conforming text

USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK_ONLY=	YES

MAKE_ENV+=	CC="${CC}"

do-install:
	${LIBTOOL} ${LIBTOOL_FLAGS} ${INSTALL_DATA} \
		${WRKSRC}/lib/libXmHTML.la ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/XmHTML
	${INSTALL_DATA} ${WRKSRC}/include/XmHTML/*.h ${PREFIX}/include/XmHTML

.include "../../mk/x11.buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
