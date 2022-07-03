# $NetBSD: Makefile,v 1.1 2022/07/03 21:07:48 pin Exp $

DISTNAME=	xbrightness-0.3
CATEGORIES=	x11
MASTER_SITES=	http://disjunkt.com/xbrightness/

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	http://disjunkt.com/xbrightness/
COMMENT=	Brightness and gamma correction through the X server
LICENSE=	mit

USE_IMAKE=	yes

.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
