# $NetBSD: Makefile,v 1.5 2014/01/14 18:52:57 wiz Exp $

DISTNAME=	libxkbcommon-0.3.2
PKGREVISION=	2
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

.include "options.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
