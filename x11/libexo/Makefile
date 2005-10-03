# $NetBSD: Makefile,v 1.1.1.1 2005/10/03 04:51:33 minskim Exp $
#

DISTNAME=		exo-0.3.0
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
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	${WRKSRC}/exo/exo-0.3.pc.in

CONFIGURE_ARGS+=	--disable-python --with-html-dir=${PREFIX}/share/doc

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
