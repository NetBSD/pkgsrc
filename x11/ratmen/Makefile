# $NetBSD: Makefile,v 1.3 2009/07/07 18:07:11 joerg Exp $

DISTNAME=	ratmen-2.2.2
CATEGORIES=	x11 wm
MASTER_SITES=	http://www.update.uu.se/~zrajm/programs/ratmen/

MAINTAINER=	lkundrak@skosi.org
HOMEPAGE=	http://www.update.uu.se/~zrajm/programs/
COMMENT=	Allows you to create X menus from the shell

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	ratmen
LDFLAGS+=	${X11_LDFLAGS}

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
