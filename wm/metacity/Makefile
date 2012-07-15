# $NetBSD: Makefile,v 1.100 2012/07/15 08:22:58 wiz Exp $
#

DISTNAME=	metacity-2.34.1
PKGREVISION=	5
CATEGORIES=	wm x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/metacity/2.34/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/softwaremap/projects/Metacity/
COMMENT=	GNOME-compliant window manager

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	src/libmetacity-private.pc.in

GCONF_SCHEMAS=		metacity.schemas

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} != "native"
.include "../../x11/libXinerama/buildlink3.mk"
.elif !exists(${X11BASE}/lib/libXinerama.so)
CONFIGURE_ARGS+=	--disable-xinerama
.endif

.if ${X11_TYPE} != "modular" && !exists(${X11BASE}/lib/libXdamage.so)
CONFIGURE_ARGS+=	--disable-compositor
.endif

CFLAGS.SunOS+=		-std=c99 -D__EXTENSIONS__
.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-ansi
.endif


BUILDLINK_API_DEPENDS.glib2+=			glib2>=2.6.0
BUILDLINK_API_DEPENDS.gtk2+=			gtk2+>=2.10.0
BUILDLINK_API_DEPENDS.startup-notification+=	startup-notification>=0.7

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
DEPENDS+=	zenity-[0-9]*:../../x11/zenity
.include "../../mk/bsd.pkg.mk"
