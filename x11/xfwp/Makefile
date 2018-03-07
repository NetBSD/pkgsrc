# $NetBSD: Makefile,v 1.6 2018/03/07 11:57:46 wiz Exp $

DISTNAME=	xfwp-1.0.3
PKGREVISION=	1
CATEGORIES=	net x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Proxies X11 protocol connections, such as through a firewall
LICENSE=	x11

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS.Linux+=	--disable-strict-compilation --disable-selective-werror

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
