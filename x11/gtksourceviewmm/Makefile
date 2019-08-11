# $NetBSD: Makefile,v 1.25 2019/08/11 13:25:13 wiz Exp $
#

DISTNAME=	gtksourceviewmm-3.2.0
PKGREVISION=	20
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtksourceviewmm/3.2/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.gnome.org/gtksourceviewmm/stable/
COMMENT=	C++ wrapper for the gtksourceview widget library
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/gtksourceviewmm-3.2.0
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl pkg-config
USE_LANGUAGES=	c c++11
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	gtksourceview/gtksourceviewmm-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gtksourceview/gtksourceviewmm.pc.in

.include "../../devel/atkmm/buildlink3.mk"
.include "../../graphics/cairomm/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pangomm/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/mm-common/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
