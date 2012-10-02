# $NetBSD: Makefile,v 1.65 2012/10/02 17:12:07 tron Exp $
#

DISTNAME=	drivel-2.0.3
PKGREVISION=	27
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=drivel/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dropline.net/drivel/
COMMENT=	LiveJournal client for the GNOME Desktop

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	YES

CPPFLAGS.NetBSD+=	-D_NETBSD_SOURCE

GCONF_SCHEMAS=		drivel.schemas

BUILDLINK_API_DEPENDS.curl+=	curl>=7.14.0nb1

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
