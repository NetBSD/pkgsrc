# $NetBSD: Makefile,v 1.11 2018/11/14 22:22:43 kleink Exp $

DISTNAME=	gtkdatabox-0.9.2.0
PKGREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkdatabox/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/gtkdatabox/
COMMENT=	TODO: Short description of the package
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gtkdatabox.pc.in

.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
