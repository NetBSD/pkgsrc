# $NetBSD: Makefile,v 1.12 2022/11/09 13:14:31 joerg Exp $

DISTNAME=		xsetroot-1.1.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X root window parameter setting program

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
