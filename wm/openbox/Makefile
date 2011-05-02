# $NetBSD: Makefile,v 1.66 2011/05/02 12:50:13 wiz Exp $

DISTNAME=	openbox-3.4.11.2
PKGREVISION=	5
CATEGORIES=	wm x11
MASTER_SITES=	http://openbox.org/dist/openbox/

MAINTAINER=	wiz@NetBSD.org
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

PKGCONFIG_OVERRIDE=	parser/obparser-3.0.pc.in
PKGCONFIG_OVERRIDE+=	render/obrender-3.0.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
LDFLAGS+=		${BUILDLINK_LDADD.libsetenv}
PKG_SYSCONFSUBDIR=	xdg
OWN_DIRS=		${PKG_SYSCONFDIR}
OWN_DIRS+=		${PKG_SYSCONFDIR}/openbox

EGDIR=			${PREFIX}/share/examples/openbox
CONF_FILES=		${EGDIR}/menu.xml ${PKG_SYSCONFDIR}/openbox/menu.xml
CONF_FILES+=		${EGDIR}/rc.xml ${PKG_SYSCONFDIR}/openbox/rc.xml
CONF_FILES+=		${EGDIR}/autostart.sh \
			    ${PKG_SYSCONFDIR}/openbox/autostart.sh

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-build
SUBST_FILES.python+=	tools/xdg-autostart/xdg-autostart
# Best we can do without pulling in a python dependency.
# Update when PYTHON_VERSION_DEFAULT changes!
SUBST_SED.python+=      -e 's,/usr/bin/env.*python,${PREFIX}/bin/python2.6,'
SUBST_MESSAGE.xdg=	Fixing path to python.
CHECK_INTERPRETER_SKIP=	lib/openbox/xdg-autostart

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
