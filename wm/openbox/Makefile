# $NetBSD: Makefile,v 1.12 2004/02/07 23:22:17 jmmv Exp $

DISTNAME=	openbox-3.1
PKGREVISION=	2
CATEGORIES=	wm x11
MASTER_SITES=	http://icculus.org/openbox/releases/

MAINTAINER=	snj@pobox.com
HOMEPAGE=	http://icculus.org/openbox/
COMMENT=	Standards compliant, light-weight and extensible window manager

BUILD_USES_MSGFMT=	YES
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
DEPENDS+=		vera-ttf>=1.10:../../fonts/vera-ttf

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/parser/obparser-3.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/render/obrender-3.0.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
PKG_SYSCONFSUBDIR=	xdg
OWN_DIRS=		${PKG_SYSCONFDIR}/openbox

EGDIR=			${PREFIX}/share/examples/openbox
CONF_FILES=		${EGDIR}/menu.xml ${PKG_SYSCONFDIR}/openbox/menu.xml
CONF_FILES+=		${EGDIR}/rc.xml ${PKG_SYSCONFDIR}/openbox/rc.xml

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
