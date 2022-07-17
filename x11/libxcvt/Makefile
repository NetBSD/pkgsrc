# $NetBSD: Makefile,v 1.3 2022/07/17 01:39:07 tnn Exp $

DISTNAME=		libxcvt-0.1.1
PKGREVISION=		1
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
