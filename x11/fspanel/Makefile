# $NetBSD: Makefile,v 1.3 2004/04/22 03:31:47 snj Exp $
#

DISTNAME=	fspanel-0.8beta1
PKGNAME=	${DISTNAME:C/beta/.0./}
CATEGORIES=	x11
MASTER_SITES=	http://www.chatjunkies.org/fspanel/

MAINTAINER=	ptiJo <ptiJo@noos.fr>
HOMEPAGE=	http://www.chatjunkies.org/fspanel/
COMMENT=	F***ing Small Panel

USE_BUILDLINK3=	YES
USE_X11=	YES
HAS_CONFIGURE=	YES

CFLAGS+=	-DHAVE_XPM -DXFT

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fspanel ${PREFIX}/bin/

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
