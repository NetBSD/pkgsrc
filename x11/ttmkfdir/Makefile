# $NetBSD: Makefile,v 1.1.1.1.2.3 2002/06/30 06:24:45 jlam Exp $
#

DISTNAME=	ttmkfdir
PKGNAME=	ttmkfdir-0
CATEGORIES=	x11
MASTER_SITES=	http://www.joerg-pommnitz.de/TrueType/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.joerg-pommnitz.de/TrueType/xfsft.html
COMMENT=	tool that creates a fonts.scale file

WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttmkfdir ${PREFIX}/bin

.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
