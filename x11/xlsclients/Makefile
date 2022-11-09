# $NetBSD: Makefile,v 1.13 2022/11/09 13:14:30 joerg Exp $

DISTNAME=		xlsclients-1.1.4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X client listing utility
LICENSE=		mit

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
