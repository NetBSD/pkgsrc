# $NetBSD: Makefile,v 1.1 2021/07/13 12:05:08 wiz Exp $

DISTNAME=		libxcvt-0.1.0
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		VESA CVT standard timing modelines generator
LICENSE=		mit

CONFLICTS+=		modular-xorg-server-[0-9]*

PKGCONFIG_OVERRIDE+=		output/meson-private/libxcvt.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
