# $NetBSD: Makefile,v 1.60 2014/02/12 23:18:48 tron Exp $

DISTNAME=		gnome-terminal-2.32.1
PKGREVISION=		21
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-terminal/2.32/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Xterm like terminal program for GNOME 2

BUILD_DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

CONFLICTS=		gnome-core-[0-9]* gnome2-terminal-[0-9]*

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

CONFIGURE_ENV+=		ac_cv_path_GTK_BUILDER_CONVERT="${PYTHONBIN} ${BUILDLINK_PREFIX.gtk2}/bin/gtk-builder-convert"

GCONF_SCHEMAS=	gnome-terminal.schemas

PYTHON_FOR_BUILD_ONLY=	YES
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 2.32.1

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.GConf+=	GConf>=2.14.0
.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.13.6
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
BUILDLINK_API_DEPENDS.startup-notification+=	startup-notification>=0.8
.include "../../x11/startup-notification/buildlink3.mk"
BUILDLINK_API_DEPENDS.vte+=	vte>=0.24.0
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
