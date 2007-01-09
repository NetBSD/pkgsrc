# $NetBSD: Makefile,v 1.9 2007/01/09 10:16:19 joerg Exp $
#

DISTNAME=	xflame-1.1.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.owlnet.rice.edu/~rahul/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Draws a flame on the screen

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_FLAGS+=	EXTRA_LOAD_FLAGS=-lrt
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
