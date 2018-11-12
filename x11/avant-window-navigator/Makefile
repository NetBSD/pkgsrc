# $NetBSD: Makefile,v 1.45 2018/11/12 03:53:05 ryoon Exp $

DISTNAME=	avant-window-navigator-0.4.0
PKGREVISION=	31
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/awn/0.4/0.4.0/+download/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://launchpad.net/awn
COMMENT=	Dock-like navigation bar
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
DEPENDS+=	bzr>=2.4.2:../../devel/bzr

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config msgfmt intltool gmake
USE_LIBTOOL=	yes

CPPFLAGS.SunOS+=	-D__EXTENSIONS__

PKGCONFIG_OVERRIDE+=	awn.pc.in

GCONF_SCHEMAS+=		avant-window-navigator.schemas
GCONF_SCHEMAS+=		awn-applet-taskmanager.schemas

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Fixing python path
SUBST_FILES.python=	applet-activation/main.c
SUBST_SED.python=	-e "s,@PYTHONBIN@,${PYTHONBIN},"

SUBST_CLASSES+=		pathfix
SUBST_STAGE.pathfix=	pre-configure
SUBST_MESSAGE.pathfix=	Fixing hardcoded paths
SUBST_FILES.pathfix=	applets/taskmanager/awn-applet-taskmanager.schema-ini.in
SUBST_FILES.pathfix+=	doc/reference/html/*.html
SUBST_FILES.pathfix+=	libawn/awn-themed-icon.c
SUBST_FILES.pathfix+=	tests/test-awn-effects.c
SUBST_FILES.pathfix+=	tests/test-overlays.py
SUBST_SED.pathfix=	-e "s,/usr/share,${PREFIX}/share,"

PY_PATCHPLIST=		yes
REPLACE_PYTHON+=	awn-settings/awnSettings.py.in
REPLACE_PYTHON+=	awn-settings/awnSettingsHelper.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2

.include "../../devel/GConf/schemas.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/libdesktop-agnostic/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
