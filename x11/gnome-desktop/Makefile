# $NetBSD: Makefile,v 1.166 2023/11/04 09:54:52 wiz Exp $

DISTNAME=		gnome-desktop-44.0
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-desktop/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnome.org/
COMMENT=		Common GNOME2 desktop files and libgnome-desktop library
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2

TOOL_DEPENDS+=		gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

#USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config
USE_TOOLS+=		itstool pkg-config

PKGCONFIG_OVERRIDE+=	output/meson-private/gnome-desktop-4.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gnome-bg-4.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gnome-rr-4.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gnome-desktop-3.0.pc

PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../devel/meson/build.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
