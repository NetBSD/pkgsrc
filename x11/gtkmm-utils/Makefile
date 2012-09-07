# $NetBSD: Makefile,v 1.10 2012/09/07 19:17:47 adam Exp $
#

DISTNAME=	gtkmm-utils-0.4.1
PKGREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	http://gtkmm-utils.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/gtkmm-utils/
COMMENT=	C++ utility and widget library based on glibmm and gtkmm

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

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
