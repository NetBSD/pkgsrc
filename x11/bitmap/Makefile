# $NetBSD: Makefile,v 1.16 2024/02/09 20:50:40 wiz Exp $

DISTNAME=		bitmap-1.1.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Bitmap editor and conversion utilities

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

MAKE_FLAGS+=		appdefaultdir=${PREFIX}/lib/X11/app-defaults

CHECK_PORTABILITY_SKIP+=	test/round-trip-test.in

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
