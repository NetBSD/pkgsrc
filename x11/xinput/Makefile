# $NetBSD: Makefile,v 1.4 2009/06/10 09:35:10 wiz Exp $
#

DISTNAME=	xinput-1.4.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Xinput diagnostic utility for modular X.org

PKG_DESTDIR_SUPPORT= 	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.inputproto+= 	inputproto>=1.5
.include "../../x11/inputproto/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXi+=		libXi>=1.2.0
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
