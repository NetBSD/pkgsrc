# $NetBSD: Makefile,v 1.5 2024/12/14 12:43:21 wiz Exp $

DISTNAME=		libxcvt-0.1.3
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		VESA CVT standard timing modelines generator
LICENSE=		mit

PKGCONFIG_OVERRIDE+=		output/meson-private/libxcvt.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
