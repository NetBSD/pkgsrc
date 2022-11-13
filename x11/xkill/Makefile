# $NetBSD: Makefile,v 1.11 2022/11/13 08:08:52 wiz Exp $

DISTNAME=		xkill-1.0.6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Kill X clients

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
