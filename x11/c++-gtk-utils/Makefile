# $NetBSD: Makefile,v 1.42 2026/09/27 11:39:12 tnn Exp $

DISTNAME=	c++-gtk-utils-2.2.19
PKGREVISION=	20
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cxx-gtk-utils/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://cxx-gtk-utils.sourceforge.net/
COMMENT=	Lightweight library for programming GTK+ programs using C++
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	c++-gtk-utils-3-2.2.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
