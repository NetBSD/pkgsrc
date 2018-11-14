# $NetBSD: Makefile,v 1.4 2018/11/14 22:22:45 kleink Exp $
#

DISTNAME=	libgnomekbd-2.32.0
PKGNAME=	libgnomekbd2-2.32.0
PKGREVISION=	26
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomekbd/2.32/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Gnome keyboard configuration library

# used a library before it was created
MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt

GCONF_SCHEMAS+=	desktop_gnome_peripherals_keyboard_xkb.schemas
PKGCONFIG_OVERRIDE+=	libgnomekbd.pc.in
PKGCONFIG_OVERRIDE+=	libgnomekbdui.pc.in

.include "../../devel/GConf/schemas.mk"
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxklavier+=	libxklavier>=4.0
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
