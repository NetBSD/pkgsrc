# $NetBSD: Makefile,v 1.3 2014/12/12 00:24:42 rodent Exp $

DISTNAME=	xfwp-1.0.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Proxies X11 protocol connections, such as through a firewall
LICENSE=	x11

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--disable-strict-compilation --disable-selective-werror
.endif

.include "../../x11/xproxymanagementprotocol/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
