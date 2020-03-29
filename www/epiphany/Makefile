# $NetBSD: Makefile,v 1.195 2020/03/29 12:21:56 nia Exp $

DISTNAME=	epiphany-3.34.3.1
PKGREVISION=	2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/epiphany/3.34/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Web
COMMENT=	Web browser for the GNOME desktop
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

USE_TOOLS+=	pkg-config msgfmt xgettext

MESON_ARGS+=	-Dunit_tests=disabled

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/epiphany

PYTHON_FOR_BUILD_ONLY=	tool

# XXX msgfmt: unknown option -- desktop
_TOOLS_USE_PKGSRC.msgfmt=	yes

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/libdazzle/buildlink3.mk"
.include "../../devel/libhandy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gcr/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
