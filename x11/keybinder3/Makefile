# $NetBSD: Makefile,v 1.9 2022/08/11 05:09:28 gutteridge Exp $

DISTNAME=	keybinder-3.0-0.3.2
PKGNAME=	keybinder3-0.3.2
PKGREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=kupferlauncher/keybinder/releases/download/keybinder-3.0-v0.3.2/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/engla/keybinder
COMMENT=	Library for registering keyboard shortcuts
LICENSE=	gnu-gpl-v2

PKGCONFIG_OVERRIDE+=	libkeybinder/keybinder-3.0.pc.in

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake autoconf automake msgfmt autoreconf

CONFIGURE_ARGS+=	--disable-static
CONFIGURE_ARGS+=	--disable-gtk-doc

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
