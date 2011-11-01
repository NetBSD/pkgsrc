# $NetBSD: Makefile,v 1.12 2011/11/01 06:03:10 sbd Exp $
#

DISTNAME=	xclock-1.0.4
PKGREVISION=	1
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
LDFLAGS+=	${BUILDLINK_LDADD.iconv}

MAKE_FLAGS+=		appdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
