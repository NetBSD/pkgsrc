# $NetBSD: Makefile,v 1.6 2014/10/09 14:07:16 wiz Exp $
#

DISTNAME=		xprehashprinterlist-1.0.1
CATEGORIES=		x11 print
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Recompute Xprint server list

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
