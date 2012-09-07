# $NetBSD: Makefile,v 1.137 2012/09/07 19:17:44 adam Exp $
#

DISTNAME=		gnome-session-2.26.2
PKGREVISION=		21
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-session/2.26/}
SITES.gnome-splash-2.16.0.png=	${MASTER_SITE_LOCAL:=gnome-splash/}
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} gnome-splash-2.16.0.png

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 session management utilities

BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		gnome-core<1.4.2nb4

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config

MAKE_ENV+=		REAL_GCONFTOOL=${GCONFTOOL2:Q}

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""
CPPFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

GCONF_SCHEMAS=		gnome-session.schemas

post-extract:
	${MV} ${WRKSRC}/data/gnome-splash.png \
	    ${WRKSRC}/data/gnome-splash-orig.png
	${CP} ${DISTDIR}/gnome-splash-2.16.0.png \
	    ${WRKSRC}/data/gnome-splash.png

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/gnome-splash-orig.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps/splash/gnome-splash-orig.png

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/GConf-ui/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/policykit/buildlink3.mk"
.include "../../security/policykit-gnome/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.76
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/gnome-settings-daemon/buildlink3.mk"
BUILDLINK_DEPMETHOD.libxslt?=	build
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gnome-control-center/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.11.1
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
