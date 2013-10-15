# $NetBSD: Makefile,v 1.4 2013/10/15 12:11:28 obache Exp $
#

DISTNAME=	libfakekey-0.1
CATEGORIES=	x11
MASTER_SITES=	http://downloads.yoctoproject.org/releases/matchbox/libfakekey/0.1/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://www.yoctoproject.org/tools-resources/projects/matchbox
COMMENT=	X Virtual Keyboard Library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libfakekey.pc.in

.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
