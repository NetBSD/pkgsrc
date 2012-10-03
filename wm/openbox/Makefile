# $NetBSD: Makefile,v 1.77.2.1 2012/10/03 12:09:41 spz Exp $

DISTNAME=	openbox-3.5.0
PKGREVISION=	9
CATEGORIES=	wm x11
MASTER_SITES=	http://openbox.org/dist/openbox/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openbox.org/
COMMENT=	Standards compliant, light-weight, and extensible window manager
LICENSE=	gnu-gpl-v2

DEPENDS+=		vera-ttf>=1.10:../../fonts/vera-ttf

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_FEATURES+=		setenv

PKGCONFIG_OVERRIDE=	obrender/obrender-3.5.pc.in
PKGCONFIG_OVERRIDE+=	obt/obt-3.5.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
LDFLAGS+=		${BUILDLINK_LDADD.libsetenv}
PKG_SYSCONFSUBDIR=	xdg
OWN_DIRS=		${PKG_SYSCONFDIR}
OWN_DIRS+=		${PKG_SYSCONFDIR}/openbox

EGDIR=			${PREFIX}/share/examples/openbox
CONF_FILES=		${EGDIR}/autostart ${PKG_SYSCONFDIR}/openbox/autostart
CONF_FILES+=		${EGDIR}/environment ${PKG_SYSCONFDIR}/openbox/environment
CONF_FILES+=		${EGDIR}/menu.xml ${PKG_SYSCONFDIR}/openbox/menu.xml
CONF_FILES+=		${EGDIR}/rc.xml ${PKG_SYSCONFDIR}/openbox/rc.xml

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-build
SUBST_FILES.python+=	data/autostart/openbox-xdg-autostart
# Best we can do without pulling in a python dependency.
# Update when PYTHON_VERSION_DEFAULT changes!
SUBST_SED.python+=      -e 's,/usr/bin/env.*python,${PREFIX}/bin/python2.7,'
SUBST_MESSAGE.python=	Fixing path to python.
CHECK_INTERPRETER_SKIP=	libexec/openbox-xdg-autostart

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
