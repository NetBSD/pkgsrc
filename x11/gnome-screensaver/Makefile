# $NetBSD: Makefile,v 1.34 2009/05/19 08:59:38 wiz Exp $
#

DISTNAME=	gnome-screensaver-2.26.1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-screensaver/2.26/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/GnomeScreensaver/
COMMENT=	Screen saver and locker for the GNOME desktop
#LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.3
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "options.mk"

PKGCONFIG_OVERRIDE=	data/gnome-screensaver.pc.in

GCONF_SCHEMAS=		gnome-screensaver.schemas

EGDIR=			${PREFIX}/share/examples/gnome-screensaver
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}
MESSAGE_SUBST+=		EGDIR=${EGDIR:Q}
MAKE_DIRS+=		${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES=		${EGDIR}/xdg/menus/gnome-screensavers.menu \
			${PKG_SYSCONFDIR}/xdg/menus/gnome-screensavers.menu

INSTALLATION_DIRS=	${EGDIR}/pam.d

post-install:
	${INSTALL_DATA} ${FILESDIR}/pam-gnome-screensaver-NetBSD \
	    ${DESTDIR}${EGDIR}/pam.d/gnome-screensaver-NetBSD
	${INSTALL_DATA} ${WRKSRC}/data/gnome-screensaver \
	    ${DESTDIR}${EGDIR}/pam.d/gnome-screensaver-Linux

.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.8.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libglade+=	libglade>=2.5.0
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libexif+=		libexif>=0.6.12
.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-desktop+=	gnome-desktop>=2.23.2
.include "../../x11/gnome-desktop/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.11.5
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libgnomekbd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
