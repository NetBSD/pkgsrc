# $NetBSD: Makefile,v 1.13 2012/09/27 10:06:31 jperkin Exp $
#

DISTNAME=	xf86-video-sis-0.10.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg SiS and XGI video driver

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-dri

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
BUILD_DEPENDS+=		ucpp-[0-9]*:../../devel/ucpp
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="${PREFIX}/bin/ucpp -t -c90 -Uunix"
.elif empty(PKGSRC_COMPILER:Mgcc)
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="cc -E -Uunix -"
.endif

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4
.endif

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"
.include "../../x11/xf86miscproto/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
