# $NetBSD: Makefile,v 1.24 2023/11/14 14:03:11 wiz Exp $

DISTNAME=	gtkdatabox-1.0.0
PKGREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkdatabox/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/gtkdatabox/
COMMENT=	GTK3 widget for live display of fluctuating numerical data
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gtkdatabox.pc.in

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
