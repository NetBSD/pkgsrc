# $NetBSD: Makefile,v 1.26 2023/11/14 14:02:58 wiz Exp $

DISTNAME=	gnome-calendar-40.0
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
PKGREVISION=	19
CATEGORIES=	time gnome
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Calendar/
COMMENT=	Calendar application for GNOME
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config msgfmt xgettext
USE_TOOLS+=	gdbus-codegen

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/libdazzle/buildlink3.mk"
.include "../../devel/libgweather/buildlink3.mk"
.include "../../devel/libhandy/buildlink3.mk"
.include "../../geography/geoclue/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../net/gnome-online-accounts/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
