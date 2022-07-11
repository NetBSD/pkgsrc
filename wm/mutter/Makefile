# $NetBSD: Makefile,v 1.11 2022/07/11 19:11:57 wiz Exp $

DISTNAME=	mutter-40.2
PKGREVISION=	1
CATEGORIES=	wm gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/mutter
COMMENT=	GNOME window manager
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		msgfmt pkg-config gdbus-codegen
BUILD_DEFS+=		PKG_SYSCONFBASE

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
PKGCONFIG_OVERRIDE+=		output/meson-private/mutter-cogl-8.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/mutter-cogl-pango-8.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/mutter-clutter-8.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/mutter-clutter-x11-8.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/libmutter-8.pc

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/mutter-8

post-extract:
	${CP} ${FILESDIR}/90-mutter ${WRKSRC}/data

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	data/90-mutter
SUBST_VARS.paths=	PREFIX

EGDIR=			${PREFIX}/share/examples/mutter
INSTALLATION_DIRS+=	share/examples/mutter/X11/xinit/xinitrc.d

post-install:
	${INSTALL_DATA}	${WRKSRC}/data/90-mutter \
		${DESTDIR}${EGDIR}/X11/xinit/xinitrc.d/90-mutter

REQD_FILES+=		${EGDIR}/X11/xinit/xinitrc.d/90-mutter \
			${PKG_SYSCONFBASE}/X11/xinit/xinitrc.d/90-mutter

.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.glib2+=				glib2>=2.67.3
.include "../../devel/glib2/schemas.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/graphene/buildlink3.mk"
.include "../../sysutils/gnome-settings-daemon/buildlink3.mk"
BUILDLINK_API_DEPENDS.gsettings-desktop-schemas+=       gsettings-desktop-schemas>=40.0
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
