# $NetBSD: Makefile,v 1.75 2006/09/15 15:18:16 jmmv Exp $
#

DISTNAME=		gnome-session-2.16.0
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-session/2.16/}
SITES.gnome-splash-2.16.0.png=	${MASTER_SITE_LOCAL:=gnome-splash/}
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} gnome-splash-2.16.0.png

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 session management utilities

CONFLICTS+=		gnome-core<1.4.2nb4

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		yes

MAKE_ENV+=		REAL_GCONFTOOL=${GCONFTOOL2:Q}

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""
CPPFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

GCONF2_SCHEMAS= 	gnome-session.schemas

BUILDLINK_API_DEPENDS.esound+=	esound>=0.2.26
BUILDLINK_API_DEPENDS.gnome-keyring+=	gnome-keyring>=0.5.1
# Make sure we do not use old packages that rely on XDG_{CONFIG,DATA}_DIRS
# in the environment being set.
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.1
BUILDLINK_API_DEPENDS.gnome-vfs2+=	gnome-vfs2>=2.8.3nb1

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/GConf2-ui/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/scrollkeeper/buildlink3.mk"
.include "../../x11/gnome2-control-center/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-extract:
	${MV} ${WRKSRC}/gnome-session/gnome-splash.png \
	    ${WRKSRC}/gnome-session/gnome-splash-orig.png
	${CP} ${DISTDIR}/gnome-splash-2.16.0.png \
	    ${WRKSRC}/gnome-session/gnome-splash.png

post-install:
	${INSTALL_DATA} ${WRKSRC}/gnome-session/gnome-splash-orig.png \
	    ${PREFIX}/share/pixmaps/splash/gnome-splash-orig.png

.include "../../mk/bsd.pkg.mk"
