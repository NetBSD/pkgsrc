# $NetBSD: Makefile,v 1.10 2005/03/17 15:49:54 wiz Exp $
#

DISTNAME=	fspanel-0.8beta1
PKGNAME=	${DISTNAME:C/beta/.0./}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.chatjunkies.org/fspanel/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://www.chatjunkies.org/fspanel/
COMMENT=	F***ing Small Panel for listing X11 windows

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
USE_X11=	YES
HAS_CONFIGURE=	YES

CFLAGS+=	-DHAVE_XPM -DXFT

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fspanel ${PREFIX}/bin/

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
