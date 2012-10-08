# $NetBSD: Makefile,v 1.15 2012/10/08 13:04:31 asau Exp $
#

DISTNAME=	xbeats-0.4
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	http://iznogood.bohemians.org/xbeats/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://iznogood.bohemians.org/
COMMENT=	Beats clock dockable in both Window Maker and AfterStep

GNU_CONFIGURE=	YES

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
