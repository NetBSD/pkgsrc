# $NetBSD: Makefile,v 1.5 2022/11/13 08:07:49 wiz Exp $

DISTNAME=		xkbevd-1.1.5
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Possible replacement for xev (work in progress)

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
