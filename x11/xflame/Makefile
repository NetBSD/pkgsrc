# $NetBSD: Makefile,v 1.14 2016/02/26 11:40:30 jperkin Exp $
#

DISTNAME=	xflame-1.1.1
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.owlnet.rice.edu/~rahul/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Draws a flame on the screen

USE_IMAKE=	yes

MAKE_FLAGS.SunOS+=	EXTRA_LOAD_FLAGS=-lrt

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
