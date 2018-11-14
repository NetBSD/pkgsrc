# $NetBSD: Makefile,v 1.34 2018/11/14 22:22:40 kleink Exp $

DISTNAME=	gnome-desktop-3.24.2
PKGNAME=	${DISTNAME:S/desktop/desktop3/}
PKGREVISION=	5
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-desktop/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://www.gnome.org/
COMMENT=	GNOME3 desktop-wide documents and libgnome-desktop library
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-fdl-v1.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	libgnome-desktop/gnome-desktop-3.0.pc.in

CONFIGURE_ARGS+=	--with-gnome-distributor="The NetBSD Foundation"
CONFIGURE_ARGS+=	--disable-date-in-gnome-version
CONFIGURE_ARGS+=	--disable-desktop-docs
CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--disable-debug-tools
CONFIGURE_ARGS+=	--disable-udev

BUILD_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.44.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.gdk-pixbuf2+=	gdk-pixbuf2>=2.36.5
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gsettings-desktop-schemas+=	gsettings-desktop-schemas>=3.5.91
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
