# $NetBSD: Makefile,v 1.34 2018/11/12 03:51:30 ryoon Exp $
#

DISTNAME=	gtkmm-utils-0.4.1
PKGREVISION=	27
CATEGORIES=	x11
MASTER_SITES=	http://gtkmm-utils.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/markoa/gtkmm-utils
COMMENT=	C++ utility and widget library based on glibmm and gtkmm
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++11
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	glibmm-utils/glibmm-utils.pc.in
PKGCONFIG_OVERRIDE+=	gtkmm-utils/gtkmm-utils.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.5
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.glibmm+=	glibmm>=2.12.0
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtkmm+=	gtkmm>=2.10.0
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
