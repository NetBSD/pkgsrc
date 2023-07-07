# $NetBSD: Makefile,v 1.18 2023/07/07 08:25:37 nia Exp $
#

DISTNAME=	xbeats-0.4
PKGREVISION=	2
CATEGORIES=	x11 time
MASTER_SITES=	https://www.cs.mun.ca/~gstarkes/wmaker/dockapps/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cs.mun.ca/~gstarkes/wmaker/dockapps/time.html
COMMENT=	Beats clock dockable in both Window Maker and AfterStep
LICENSE=	gnu-gpl-v1

GNU_CONFIGURE=	YES

LDFLAGS.SunOS+=	-lX11

CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
