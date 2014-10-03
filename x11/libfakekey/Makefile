# $NetBSD: Makefile,v 1.5 2014/10/03 13:56:43 obache Exp $
#

DISTNAME=	libfakekey-0.1
CATEGORIES=	x11
MASTER_SITES=	http://downloads.yoctoproject.org/releases/matchbox/libfakekey/0.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
