# $NetBSD: Makefile,v 1.18 2025/02/03 08:06:17 wiz Exp $

DISTNAME=	xhost-1.0.10
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Server access control program for X

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

# Fix build failure by disabling gettext which is not used any way.
# So, we don't need xgettext(1).
CONFIGURE_ENV+=		ac_cv_search_gettext=no

.include "options.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
