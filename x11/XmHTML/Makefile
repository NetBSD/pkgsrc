# $NetBSD: Makefile,v 1.60 2023/11/12 13:23:59 wiz Exp $
#

DISTNAME=	XmHTML-1.1.10
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmhtml/}
EXTRACT_SUFX=	.tgz
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/xmhtml/
COMMENT=	Motif Widget capable of displaying HTML 3.2 conforming text
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	gmake
USE_LIBTOOL=	YES

INSTALLATION_DIRS=	include/XmHTML lib

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/lib/libXmHTML.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/XmHTML/*.h ${DESTDIR}${PREFIX}/include/XmHTML

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
