# $NetBSD: Makefile,v 1.1.1.1 2007/03/23 19:42:38 drochner Exp $
#

DISTNAME=	compiz-0.3.6
CATEGORIES=	wm x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.go-compiz.org/
COMMENT=	Compositing window manager

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

GCONF2_SCHEMAS+=	gwd.schemas
GCONF2_SCHEMAS+=	compiz.schemas
PKGCONFIG_OVERRIDE+=	compiz.pc.in
PKGCONFIG_OVERRIDE+=	libdecoration/libdecoration.pc.in

# this is as much as needed for the basic window decorator
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"

.include "../../devel/GConf2/schemas.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
