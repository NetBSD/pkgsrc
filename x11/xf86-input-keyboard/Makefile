# $NetBSD: Makefile,v 1.1.1.1 2006/11/14 17:15:00 joerg Exp $

DISTNAME=	xf86-input-keyboard-1.1.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/driver/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
COMMENT=	Modular Xorg keyboard driver

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
