# $NetBSD: Makefile,v 1.1.1.1 2010/08/30 09:42:41 obache Exp $
#

DISTNAME=	libfakekey-0.1
CATEGORIES=	x11
MASTER_SITES=	http://matchbox-project.org/sources/libfakekey/0.1/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://matchbox-project.org/
COMMENT=	X Virtual Keyboard Library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libfakekey.pc.in

.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
