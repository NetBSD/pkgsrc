# $NetBSD: Makefile,v 1.14.2.1 2006/11/23 12:23:28 ghen Exp $
#

DISTNAME=	gnome-screensaver-2.16.0
PKGREVISION=	3
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-screensaver/2.16/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://live.gnome.org/GnomeScreensaver/
COMMENT=	Screen saver and locker for the GNOME desktop

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.3
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_X11=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
# gnome-screensaver-dialog drops SUID privs
CONFIGURE_ARGS+=	--disable-pam
.endif

PKGCONFIG_OVERRIDE=	data/gnome-screensaver.pc

GCONF2_SCHEMAS=		gnome-screensaver.schemas

EGDIR=			${PREFIX}/share/examples/gnome-screensaver
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}
MESSAGE_SUBST+=		EGDIR=${EGDIR:Q}
MAKE_DIRS+=		${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES=		${EGDIR}/xdg/menus/gnome-screensavers.menu \
			${PKG_SYSCONFDIR}/xdg/menus/gnome-screensavers.menu

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.8.0
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.8.0
BUILDLINK_API_DEPENDS.libexif+=		libexif>=0.6.12
BUILDLINK_API_DEPENDS.libglade2+=	libglade2>=2.5.0

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}/pam.d
	${INSTALL_DATA} ${FILESDIR}/pam-gnome-screensaver-NetBSD \
		${EGDIR}/pam.d/gnome-screensaver-NetBSD
	${INSTALL_DATA} ${WRKSRC}/data/gnome-screensaver \
		${EGDIR}/pam.d/gnome-screensaver-Linux
	${CHMOD} 04555 ${PREFIX}/libexec/gnome-screensaver-dialog

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
