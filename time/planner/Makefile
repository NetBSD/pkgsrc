# $NetBSD: Makefile,v 1.35 2012/09/07 19:17:37 adam Exp $
#

DISTNAME=	planner-0.14.4
PKGREVISION=	18
CATEGORIES=	time x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/planner/0.14/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Planner
COMMENT=	Project management tool for the GNOME desktop
LICENSE=	gnu-gpl-v2 # OR any later version

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
MAKE_JOBS_SAFE=		no

PKGCONFIG_OVERRIDE=	libplanner-1.pc.in

CONFIGURE_ARGS+=	--enable-python=no

GCONF_SCHEMAS=		planner.schemas

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
