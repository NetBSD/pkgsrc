# $NetBSD: Makefile,v 1.3 2009/06/07 11:24:35 wiz Exp $
#

DISTNAME=	openbsd-input-ws-1.2
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://xenocara.org/src/

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://xenocara.org/
COMMENT=	OpenBSD's wscons input driver for modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
