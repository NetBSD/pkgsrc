# $NetBSD: Makefile,v 1.13 2009/06/07 11:24:37 wiz Exp $
#

DISTNAME=	xf86-video-radeonhd-1.2.5
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://wiki.x.org/wiki/radeonhd
COMMENT=	Modular X.org driver for Radeon HD series

PKG_DESTDIR_SUPPORT=    user-destdir

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=     gmake pkg-config

CONFIGURE_ENV+=	ac_cv_file___src_AtomBios_includes_atombios_h=yes
CONFIGURE_ENV+=	ac_cv_file___src_AtomBios_includes_Decoder_h=yes

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
