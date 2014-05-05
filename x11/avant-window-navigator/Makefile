# $NetBSD: Makefile,v 1.21 2014/05/05 00:48:27 ryoon Exp $

DISTNAME=	avant-window-navigator-0.4.0
PKGREVISION=	16
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

PKGCONFIG_OVERRIDE+=	awn.pc.in

GCONF_SCHEMAS+=		avant-window-navigator.schemas
GCONF_SCHEMAS+=		awn-applet-taskmanager.schemas

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-patch
SUBST_MESSAGE.python=	Fixing python path
SUBST_FILES.python=	applet-activation/main.c
SUBST_SED.python=	-e "s,@PYTHONBIN@,${PYTHONBIN},"

SUBST_CLASSES+=		pathfix
SUBST_STAGE.pathfix=	post-patch
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
PYTHON_VERSIONED_DEPENDENCIES=	cairo:link
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-gtk2

.include "../../devel/GConf/schemas.mk"
.include "../../lang/vala014/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
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
