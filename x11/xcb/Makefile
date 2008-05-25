# $NetBSD: Makefile,v 1.11 2008/05/25 14:45:18 tron Exp $

DISTNAME=	xcb-2.4
CATEGORIES=	x11
MASTER_SITES=	http://www.goof.com/pcg/marc/data/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.goof.com/pcg/marc/xcb.html
COMMENT=	Extensible, multiple cut buffers for X

USE_IMAKE=	YES
BUILD_TARGET=	all Xcb.ad

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
