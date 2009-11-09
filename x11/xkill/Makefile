# $NetBSD: Makefile,v 1.4 2009/11/09 18:48:46 tnn Exp $
#

DISTNAME=		xkill-1.0.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Kill X clients

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
