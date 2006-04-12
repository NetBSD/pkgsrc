# $NetBSD: Makefile,v 1.1.1.1 2006/04/12 17:14:35 minskim Exp $

DISTNAME=	ratmen-2.2.2
CATEGORIES=	x11 wm
MASTER_SITES=	http://www.update.uu.se/~zrajm/programs/ratmen/

MAINTAINER=	lkundrak@skosi.org
HOMEPAGE=	http://www.update.uu.se/~zrajm/programs/
COMMENT=	Allows you to create X menus from the shell

BUILD_TARGET=	ratmen
LDFLAGS+=	${X11_LDFLAGS}

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
