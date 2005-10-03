# $NetBSD: Makefile,v 1.35 2005/10/03 17:52:42 joerg Exp $
#

DISTNAME=       XmHTML-1.1.7
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=   http://www.xs4all.nl/~ripley/XmHTML/dist/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.xs4all.nl/~ripley/XmHTML/
COMMENT=	Motif Widget capable of displaying HTML 3.2 conforming text

USE_X11BASE=	YES
USE_TOOLS+=	gmake
USE_LIBTOOL=	YES

INSTALLATION_DIRS=	lib

do-install:
	${LIBTOOL} ${LIBTOOL_FLAGS} ${INSTALL_LIB} \
		${WRKSRC}/lib/libXmHTML.la ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/XmHTML
	${INSTALL_DATA} ${WRKSRC}/include/XmHTML/*.h ${PREFIX}/include/XmHTML

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
