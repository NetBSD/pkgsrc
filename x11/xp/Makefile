# $NetBSD: Makefile,v 1.13 2008/11/10 17:21:39 wiz Exp $

DISTNAME=	xp-1.2b10
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.ncl.ac.uk/pub/users/ngmt/X11/

MAINTAINER=	jdc@NetBSD.org
COMMENT=	Fast X11 text file viewer using Athena widgets

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes
MAKE_FLAGS+=	MANPATH=${PREFIX}/${PKGMANDIR}

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
