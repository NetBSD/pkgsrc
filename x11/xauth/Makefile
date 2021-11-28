# $NetBSD: Makefile,v 1.13 2021/11/28 23:56:22 wiz Exp $

DISTNAME=		xauth-1.1.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X authentication utility

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
CPPFLAGS.NetBSD+=	-D_OPENBSD_SOURCE

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
