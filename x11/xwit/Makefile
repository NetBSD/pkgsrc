# $NetBSD: Makefile,v 1.13 2012/10/29 05:07:25 asau Exp $
#

DISTNAME=	xwit-3.4
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utility for calling X11 functions from the shell

USE_IMAKE=	yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
