# $NetBSD: Makefile,v 1.54 2013/01/26 21:36:51 adam Exp $
#

DISTNAME=	XmHTML-1.1.7
PKGREVISION=	13
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
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
