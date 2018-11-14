# $NetBSD: Makefile,v 1.60 2018/11/14 22:22:32 kleink Exp $

DISTNAME=	hamster-applet-2.28.1
PKGREVISION=	38
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/hamster-applet/2.28/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://projecthamster.wordpress.com/
COMMENT=	Time tracking applet for GNOME
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config msgfmt

GCONF_SCHEMAS+=	hamster-applet.schemas
PY_PATCHPLIST=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit via py-gnome2, py-gtk2

SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	Fixing path to Python interpreter.
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	hamster/hamster-applet.py
SUBST_SED.python=	-e 's@/usr/bin/env python@${PYTHONBIN}@g'

.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
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
