# $NetBSD: Makefile,v 1.3 2012/10/29 05:06:37 asau Exp $
#

DISTNAME=	libfakekey-0.1
CATEGORIES=	x11
MASTER_SITES=	http://matchbox-project.org/sources/libfakekey/0.1/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://matchbox-project.org/
COMMENT=	X Virtual Keyboard Library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libfakekey.pc.in

.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
