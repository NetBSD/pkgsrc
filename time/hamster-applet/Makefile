# $NetBSD: Makefile,v 1.1.1.1 2008/12/02 22:36:35 wiz Exp $
#

DISTNAME=	hamster-applet-2.24.2
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/hamster-applet/2.24/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projecthamster.wordpress.com/
COMMENT=	Time tracking applet for GNOME

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
MAKE_ENV+=	GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config

GCONF_SCHEMAS+=	hamster-applet.schemas
PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"

.if ${PYPKGPREFIX} == "py24"
.include "../../databases/py-sqlite2/buildlink3.mk"
.else
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
.endif
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.pygobject+= 	${PYPKGPREFIX}-gobject>=2.14
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.12.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gnome2-desktop/buildlink3.mk"
BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.12
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
