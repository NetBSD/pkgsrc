# $NetBSD: Makefile,v 1.211 2022/08/11 05:09:22 gutteridge Exp $

DISTNAME=	epiphany-40.6
PKGREVISION=	2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/epiphany/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Web
COMMENT=	Web browser for the GNOME desktop
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config msgfmt xgettext itstool
USE_TOOLS+=	gdbus-codegen

MESON_ARGS+=	-Dlibportal=disabled
MESON_ARGS+=	-Dunit_tests=disabled

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/epiphany

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.64.0
.include "../../devel/glib2/schemas.mk"
BUILDLINK_API_DEPENDS.libdazzle+=	libdazzle>=3.37.1
.include "../../devel/libdazzle/buildlink3.mk"
BUILDLINK_API_DEPENDS.libhandy+=	libhandy>=1.1.0
.include "../../devel/libhandy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gcr/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
BUILDLINK_API_DEPENDS.json-glib+=	json-glib>=1.6
.include "../../textproc/json-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.webkit-gtk+=	webkit-gtk>=2.31.1
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
