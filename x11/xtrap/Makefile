# $NetBSD: Makefile,v 1.1 2015/07/02 12:38:33 rodent Exp $
#

DISTNAME=	xtrap-1.0.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	XTrap sample clients
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/trapproto/buildlink3.mk"
.include "../../x11/libXTrap/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
