# $NetBSD: Makefile,v 1.31 2006/09/03 14:27:59 wiz Exp $

DISTNAME=	openbox-3.3
CATEGORIES=	wm x11
MASTER_SITES=	http://icculus.org/openbox/releases/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://icculus.org/openbox/
COMMENT=	Standards compliant, light-weight and extensible window manager

DEPENDS+=		vera-ttf>=1.10:../../fonts/vera-ttf

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

PKGCONFIG_OVERRIDE=	parser/obparser-3.0.pc.in
PKGCONFIG_OVERRIDE+=	render/obrender-3.0.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
PKG_SYSCONFSUBDIR=	xdg
OWN_DIRS=		${PKG_SYSCONFDIR}/openbox

EGDIR=			${PREFIX}/share/examples/openbox
CONF_FILES=		${EGDIR}/menu.xml ${PKG_SYSCONFDIR}/openbox/menu.xml
CONF_FILES+=		${EGDIR}/rc.xml ${PKG_SYSCONFDIR}/openbox/rc.xml

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
# disabled by default in 3.3 because "it doesn't seem to work well"
#.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
