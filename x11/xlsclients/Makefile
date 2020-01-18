# $NetBSD: Makefile,v 1.12 2020/01/18 23:36:10 rillig Exp $

DISTNAME=		xlsclients-1.1.4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X client listing utility
LICENSE=		mit

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
