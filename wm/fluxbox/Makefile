# $NetBSD: Makefile,v 1.68 2020/03/20 11:58:32 nia Exp $

DISTNAME=	fluxbox-1.3.7
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fluxbox/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	sborrill@NetBSD.org
HOMEPAGE=	http://fluxbox.sourceforge.net/
COMMENT=	Window Manager for X based on Blackbox
LICENSE=	mit

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	YES
EXTRACT_USING=	bsdtar

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--enable-shape
CONFIGURE_ARGS+=	--enable-xinerama

.include "options.mk"

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Msunpro)
CXXFLAGS+=		-template=no%extdef
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
