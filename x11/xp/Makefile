# $NetBSD: Makefile,v 1.17 2016/03/10 07:40:23 wiz Exp $

DISTNAME=	xp-1.2b10
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	# ftp://ftp.ncl.ac.uk/pub/users/ngmt/X11/

MAINTAINER=	jdc@NetBSD.org
COMMENT=	Fast X11 text file viewer using Athena widgets

USE_IMAKE=	yes
MAKE_FLAGS+=	MANPATH=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	XPTOP=${PREFIX}
MAKE_FLAGS+=	XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
