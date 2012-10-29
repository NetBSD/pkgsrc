# $NetBSD: Makefile,v 1.52 2012/10/29 05:06:07 asau Exp $
#

DISTNAME=	XmHTML-1.1.7
PKGREVISION=	11
CATEGORIES=	x11
MASTER_SITES=	# http://www.xs4all.nl/~ripley/XmHTML/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.xs4all.nl/~ripley/XmHTML/
COMMENT=	Motif Widget capable of displaying HTML 3.2 conforming text
LICENSE=	gnu-lgpl-v2

USE_X11BASE=	YES
USE_TOOLS+=	gmake
USE_LIBTOOL=	YES

INSTALLATION_DIRS=	include/XmHTML lib

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/lib/libXmHTML.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/XmHTML/*.h ${DESTDIR}${PREFIX}/include/XmHTML

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
