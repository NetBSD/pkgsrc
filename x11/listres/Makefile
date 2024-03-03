# $NetBSD: Makefile,v 1.13 2024/03/03 20:58:18 wiz Exp $

DISTNAME=		listres-1.0.6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		List resources in widgets
LICENSE=		mit

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
