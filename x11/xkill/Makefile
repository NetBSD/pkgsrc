# $NetBSD: Makefile,v 1.7 2013/09/09 09:34:49 wiz Exp $

DISTNAME=		xkill-1.0.4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Kill X clients

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
