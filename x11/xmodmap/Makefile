# $NetBSD: Makefile,v 1.12 2022/11/09 13:14:30 joerg Exp $

DISTNAME=		xmodmap-1.0.11
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X modmap program

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
