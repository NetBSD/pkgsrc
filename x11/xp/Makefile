# $NetBSD: Makefile,v 1.11 2006/12/27 13:37:46 joerg Exp $

DISTNAME=	xp-1.2b10
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.ncl.ac.uk/pub/users/ngmt/X11/

MAINTAINER=	jdc@NetBSD.org
COMMENT=	Fast X11 text file viewer using Athena widgets

USE_IMAKE=	yes
MAKE_FLAGS+=	MANPATH=${PREFIX}/${PKGMANDIR}

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
