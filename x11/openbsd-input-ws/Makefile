# $NetBSD: Makefile,v 1.7 2014/05/05 00:48:31 ryoon Exp $
#

DISTNAME=	openbsd-input-ws-1.2
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://xenocara.org/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xenocara.org/
COMMENT=	OpenBSD's wscons input driver for modular X.org

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
