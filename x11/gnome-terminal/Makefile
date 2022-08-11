# $NetBSD: Makefile,v 1.101 2022/08/11 05:09:26 gutteridge Exp $

DISTNAME=	gnome-terminal-3.36.2
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-terminal/${PKGVERSION_NOREV:R}/}
PKGREVISION=	3
CATEGORIES=	x11 gnome
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Terminal
COMMENT=	Terminal emulator for GNOME
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2

GNU_CONFIGURE=	yes

USE_TOOLS+=	pkg-config gmake itstool
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_TOOLS+=	gdbus-codegen

CONFIGURE_ARGS+=	--disable-search-provider
CONFIGURE_ARGS+=	--without-nautilus-extension

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/systemd/user/gnome-terminal-server.service

.include "../../devel/dconf/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/vte3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
