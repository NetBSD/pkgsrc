# $NetBSD: Makefile,v 1.16 2020/08/17 20:17:50 leot Exp $

DISTNAME=	gtkdatabox-0.9.2.0
PKGREVISION=	13
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkdatabox/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/gtkdatabox/
COMMENT=	GTK2 widget for live display of fluctuating numerical data
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gtkdatabox.pc.in

.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
