# $NetBSD: Makefile,v 1.7 2024/10/13 07:29:03 wiz Exp $

DISTNAME=		xkbprint-1.0.7
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Generate printable description of a XKB keyboard description

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
