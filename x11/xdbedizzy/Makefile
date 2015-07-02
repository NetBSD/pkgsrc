# $NetBSD: Makefile,v 1.1 2015/07/02 12:38:32 rodent Exp $
#

DISTNAME=	xdbedizzy-1.1.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Demo of the X11 Double Buffer Extension (DBE)
#LICENSE=	# XXX mit?

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
