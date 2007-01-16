# $NetBSD: Makefile,v 1.6 2007/01/16 20:25:55 joerg Exp $
#

DISTNAME=		exo-0.3.0
PKGREVISION=		3
CATEGORIES=		x11
MASTER_SITES=		http://download.berlios.de/xfce-goodies/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		yui@yui.pe.kr
HOMEPAGE=		http://libexo.os-cillation.com/
COMMENT=		Extension library to Xfce

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_TOOLS+=		pkg-config msgfmt

PKGCONFIG_OVERRIDE+=	${WRKSRC}/exo/exo-0.3.pc.in

CONFIGURE_ARGS+=	--disable-python --with-html-dir=${PREFIX}/share/doc

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
