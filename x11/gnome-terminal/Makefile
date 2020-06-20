# $NetBSD: Makefile,v 1.93 2020/06/20 15:05:48 nia Exp $

DISTNAME=	gnome-terminal-3.36.2
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-terminal/${PKGVERSION_NOREV:R}/}
CATEGORIES=	x11 gnome
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Terminal
COMMENT=	Terminal emulator for GNOME
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2

GNU_CONFIGURE=	yes

USE_TOOLS+=	pkg-config gmake
USE_TOOLS+=	msgfmt msgmerge xgettext

CONFIGURE_ARGS+=	--disable-search-provider
CONFIGURE_ARGS+=	--without-nautilus-extension

# XXX msgfmt: unknown option -- desktop
# XXX msgfmt: unknown option -- xml
_TOOLS_USE_PKGSRC.msgfmt=	yes

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/systemd/user/gnome-terminal-server.service

.include "../../devel/dconf/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/vte3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
