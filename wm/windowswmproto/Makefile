# $NetBSD: Makefile,v 1.2 2017/09/16 19:27:22 wiz Exp $

DISTNAME=	windowswmproto-1.0.4
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Provides definition of the WindowsWM extension to the X11 protocol
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

PKGCONFIG_OVERRIDE+=	windowswmproto.pc.in

.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
