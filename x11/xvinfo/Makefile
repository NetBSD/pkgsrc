# $NetBSD: Makefile,v 1.6 2012/06/03 18:29:52 wiz Exp $
#

DISTNAME=		xvinfo-1.1.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Query X-Video capabilities

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
