# $NetBSD: Makefile,v 1.17 2014/09/25 19:43:06 jperkin Exp $
#

DISTNAME=	xbeats-0.4
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	http://iznogood.bohemians.org/xbeats/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://iznogood.bohemians.org/
COMMENT=	Beats clock dockable in both Window Maker and AfterStep

GNU_CONFIGURE=	YES

LDFLAGS.SunOS+=	-lX11

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
