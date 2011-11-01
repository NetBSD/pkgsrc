# $NetBSD: Makefile,v 1.10 2011/11/01 06:02:48 sbd Exp $
#

DISTNAME=	eekboard-0.0.7
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://cloud.github.com/downloads/ueno/eekboard/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://fedorahosted.org/eekboard/
COMMENT=	Virtual keyboard for GNOME
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config intltool msgfmt msgmerge xgettext

PKGCONFIG_OVERRIDE+=	eek/eek-xkl-0.1.pc.in
PKGCONFIG_OVERRIDE+=	eek/eek-0.1.pc.in
PKGCONFIG_OVERRIDE+=	eek/eek-xkb-0.1.pc.in
PKGCONFIG_OVERRIDE+=	eek/eek-clutter-0.1.pc.in
PKGCONFIG_OVERRIDE+=	eek/eek-gtk-0.1.pc.in

TEST_TARGET=		check

.include "options.mk"

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/at-spi/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libfakekey/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
