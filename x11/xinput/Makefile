# $NetBSD: Makefile,v 1.11 2013/05/16 05:47:01 richard Exp $
#

DISTNAME=	xinput-1.6.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Xinput diagnostic utility for modular X.org
LICENSE=		mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.inputproto+=	inputproto>=1.6
.include "../../x11/inputproto/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXi+=		libXi>=1.2.0
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
