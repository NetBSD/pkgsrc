# $NetBSD: Makefile,v 1.1.1.1 2003/07/23 16:59:53 jschauma Exp $
#

DISTNAME=	fspanel-0.8beta1
PKGNAME=	${DISTNAME:C/beta/.0./}
CATEGORIES=	x11
MASTER_SITES=	http://www.chatjunkies.org/fspanel/

MAINTAINER=	ptiJo <ptiJo@noos.fr>
HOMEPAGE=	http://www.chatjunkies.org/fspanel/
COMMENT=	F***ing Small Panel

USE_BUILDLINK2=	YES
USE_X11=	YES
HAS_CONFIGURE=	YES

CFLAGS+=	-DHAVE_XPM -DXFT

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fspanel ${PREFIX}/bin/

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
