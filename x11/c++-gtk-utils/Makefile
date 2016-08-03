# $NetBSD: Makefile,v 1.5 2016/08/03 10:22:20 adam Exp $

DISTNAME=	c++-gtk-utils-2.2.11
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cxx-gtk-utils/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://cxx-gtk-utils.sourceforge.net/
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
