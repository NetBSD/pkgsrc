# $NetBSD: Makefile,v 1.4 2012/10/29 05:06:48 asau Exp $

DISTNAME=	ratmen-2.2.2
CATEGORIES=	x11 wm
MASTER_SITES=	http://www.update.uu.se/~zrajm/programs/ratmen/

MAINTAINER=	lkundrak@skosi.org
HOMEPAGE=	http://www.update.uu.se/~zrajm/programs/
COMMENT=	Allows you to create X menus from the shell

BUILD_TARGET=	ratmen
LDFLAGS+=	${X11_LDFLAGS}

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
