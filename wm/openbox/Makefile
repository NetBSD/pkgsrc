# $NetBSD: Makefile,v 1.112 2022/06/30 11:18:57 nia Exp $

DISTNAME=	openbox-3.6.1
PKGREVISION=	19
CATEGORIES=	wm x11
MASTER_SITES=	http://openbox.org/dist/openbox/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://openbox.org/
COMMENT=	Standards compliant, light-weight, and extensible window manager
LICENSE=	gnu-gpl-v2

DEPENDS+=		vera-ttf>=1.10:../../fonts/vera-ttf

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_FEATURES+=		setenv

PKGCONFIG_OVERRIDE=	obrender/obrender-3.5.pc.in
PKGCONFIG_OVERRIDE+=	obt/obt-3.5.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}
LDFLAGS+=		${BUILDLINK_LDADD.libsetenv}
PKG_SYSCONFSUBDIR=	xdg/openbox

EGDIR=			${PREFIX}/share/examples/openbox
CONF_FILES=		${EGDIR}/autostart ${PKG_SYSCONFDIR}/autostart
CONF_FILES+=		${EGDIR}/environment ${PKG_SYSCONFDIR}/environment
CONF_FILES+=		${EGDIR}/menu.xml ${PKG_SYSCONFDIR}/menu.xml
CONF_FILES+=		${EGDIR}/rc.xml ${PKG_SYSCONFDIR}/rc.xml

INSTALL_MAKE_FLAGS+=	rcdir=${EGDIR}

REPLACE_PYTHON+=	data/autostart/openbox-xdg-autostart

.include "options.mk"

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
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
