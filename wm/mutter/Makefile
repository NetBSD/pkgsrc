# $NetBSD: Makefile,v 1.5 2020/11/22 00:05:09 gutteridge Exp $

DISTNAME=	mutter-3.38.1
CATEGORIES=	wm gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://gitlab.gnome.org/GNOME/mutter
COMMENT=	GNOME window manager
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		msgfmt pkg-config
TOOL_DEPENDS+=		gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

.include "../../graphics/MesaLib/features.mk"

.if ${MESALIB_SUPPORTS_EGL} == "no"
MESON_ARGS+=		-Degl=false
.endif

.if ${MESALIB_SUPPORTS_GLESv2} == "no"
MESON_ARGS+=		-Dgles2=false
.endif

MESON_ARGS+=		-Dudev=false
MESON_ARGS+=		-Dnative_backend=false
MESON_ARGS+=		-Dlibwacom=false
MESON_ARGS+=		-Dremote_desktop=false
MESON_ARGS+=		-Dprofiler=false
MESON_ARGS+=		-Dwayland=false
MESON_ARGS+=		-Dtests=false #tests require Wayland support
MESON_ARGS+=		-Dsm=true
MESON_ARGS+=		-Dverbose=true

.if ${OPSYS} == "NetBSD"
MESON_ARGS+=		-Dopengl_libname=libGL.so
TOOLS_PLATFORM.msgfmt=
.endif

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/mutter-cogl-7.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/mutter-cogl-pango-7.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/mutter-clutter-7.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/mutter-clutter-x11-7.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/libmutter-7.pc

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/mutter-7

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/graphene/buildlink3.mk"
.include "../../sysutils/gnome-settings-daemon/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
