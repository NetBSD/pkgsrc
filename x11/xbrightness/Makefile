# $NetBSD: Makefile,v 1.3 2025/10/12 07:41:31 vins Exp $

DISTNAME=	xbrightness-0.3
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://disjunkt.com/xbrightness/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	http://disjunkt.com/xbrightness/
COMMENT=	Brightness and gamma correction through the X server
LICENSE=	mit

USE_IMAKE=	yes

MAKE_FLAGS+=	INSTALL=${INSTALL:Q}
MAKE_FLAGS+=	CCOPTIONS=${CFLAGS:Q}
MAKE_FLAGS+=	LOCAL_LDFLAGS=${LDFLAGS:Q}

.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
