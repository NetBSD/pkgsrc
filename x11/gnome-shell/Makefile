# $NetBSD: Makefile,v 1.20 2022/06/28 11:37:52 wiz Exp $

DISTNAME=	gnome-shell-40.2
PKGREVISION=	7
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/GnomeShell
COMMENT=	Next generation GNOME shell
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config perl msgfmt xgettext gdbus-codegen

MESON_ARGS+=	-Dnetworkmanager=false
MESON_ARGS+=	-Dsystemd=false
MESON_ARGS+=	-Dextensions_app=false
MESON_ARGS+=	-Dextensions_tool=false
MESON_ARGS+=	-Dman=true

TOOL_DEPENDS+=	sassc>=3.6:../../www/sassc
TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

DEPENDS+=	libgdm>=40.0:../../x11/libgdm

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/subprojects/gvc

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/gnome-shell

CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/gnome-shell-overrides-migration.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/gnome-shell-overrides-migration.desktop

PYTHON_FOR_BUILD_ONLY=	tool

post-extract:
	cp ${FILESDIR}/*.xml ${WRKSRC}/data/dbus-interfaces/

.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.libgweather+=	libgweather>=40.0
.include "../../devel/libgweather/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../archivers/gnome-autoar/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/at-spi2-atk/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../lang/gjs/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../security/gcr/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../wm/mutter/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
