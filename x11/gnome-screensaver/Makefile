# $NetBSD: Makefile,v 1.58 2012/10/02 17:12:12 tron Exp $
#

DISTNAME=	gnome-screensaver-2.30.2
PKGREVISION=	11
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-screensaver/2.30/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/GnomeScreensaver/
COMMENT=	Screen saver and locker for the GNOME desktop
#LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND others

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
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

SUBST_CLASSES+=		flavour
SUBST_STAGE.flavour=	pre-install
SUBST_FILES.flavour=	savers/netbsd-floaters.desktop.in
SUBST_SED.flavour=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.flavour=	Preparing NetBSD flavoured screensaver

post-extract:
	cp ${FILESDIR}/netbsd-floaters.desktop.in ${WRKSRC}/savers/

post-install:
	${INSTALL_DATA} ${FILESDIR}/pam-gnome-screensaver-NetBSD \
	    ${DESTDIR}${EGDIR}/pam.d/gnome-screensaver-NetBSD
	${INSTALL_DATA} ${WRKSRC}/data/gnome-screensaver \
	    ${DESTDIR}${EGDIR}/pam.d/gnome-screensaver-Linux
	${INSTALL_DATA} ${FILESDIR}/NetBSD-screensaver.svg \
	    ${DESTDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/savers/netbsd-floaters.desktop.in \
	    ${DESTDIR}${PREFIX}/share/applications/screensavers/netbsd-floaters.desktop

.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.8.0
.include "../../devel/glib2/buildlink3.mk"
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
