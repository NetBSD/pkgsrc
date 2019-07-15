# $NetBSD: Makefile,v 1.16 2019/07/15 07:03:06 wiz Exp $

DISTNAME=	xcb-2.4
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.goof.com/pcg/marc/data/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.goof.com/pcg/marc/xcb.html
COMMENT=	Extensible, multiple cut buffers for X

USE_IMAKE=	YES
BUILD_TARGET=	all Xcb.ad
MAKE_ENV+=	LOCAL_LDFLAGS=${LDFLAGS:Q}

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
