# $NetBSD: Makefile,v 1.15 2008/07/14 12:56:20 joerg Exp $

DISTNAME=	xwatchwin
PKGNAME=	xwatchwin-1.1.1
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://sunsite.uio.no/pub/X11/contrib/utilities/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Watch a window on another X server

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
