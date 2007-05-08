# $NetBSD: Makefile,v 1.2 2007/05/08 15:49:22 joerg Exp $
#

DISTNAME=	gnome-compiz-manager-0.10.4
CATEGORIES=	wm
MASTER_SITES=	http://download.gna.org/gcm/gnome-compiz-manager/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compiz.org/Gnome_Compiz_Manager
COMMENT=	Utility to manage GL Desktop configuration

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt
USE_DIRS+=	xdg-1.1

GCONF2_SCHEMAS+=	gnome-compiz-preferences.schemas
PKGCONFIG_OVERRIDE+=	gnome-compiz-manager.pc.in

.include "../../devel/GConf2/schemas.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
