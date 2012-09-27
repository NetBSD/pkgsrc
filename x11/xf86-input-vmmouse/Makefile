# $NetBSD: Makefile,v 1.12 2012/09/27 10:06:28 jperkin Exp $

DISTNAME=	xf86-input-vmmouse-12.6.6
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg VMware virtual mouse driver

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4
.endif

.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
