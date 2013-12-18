# $NetBSD: Makefile,v 1.4 2013/12/18 19:12:03 wiz Exp $

DISTNAME=	libxkbcommon-0.3.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xkbcommon.org/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://xkbcommon.org/
COMMENT=	Library to handle keyboard descriptions
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	bison gmake pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	xkbcommon.pc.in

CONFIGURE_ARGS+=	--with-xkb-config-root=${X11BASE}/lib/X11/xkb

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
