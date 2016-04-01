# $NetBSD: Makefile,v 1.19 2016/04/01 10:23:44 jperkin Exp $

DISTNAME=	xp-1.2b10
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	# ftp://ftp.ncl.ac.uk/pub/users/ngmt/X11/

MAINTAINER=	jdc@NetBSD.org
COMMENT=	Fast X11 text file viewer using Athena widgets

USE_IMAKE=	yes
MAKE_FLAGS+=	CCOPTIONS=${CFLAGS:Q}
MAKE_FLAGS+=	EXTRA_LDOPTIONS=${LDFLAGS:Q}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=	XPTOP=${PREFIX}
MAKE_FLAGS+=	XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
