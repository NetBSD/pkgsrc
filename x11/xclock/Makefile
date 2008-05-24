# $NetBSD: Makefile,v 1.7 2008/05/24 21:45:16 tnn Exp $
#

DISTNAME=	xclock-1.0.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Analog / digital clock for X

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ENV+=	APP_MAN_SUFFIX=1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
