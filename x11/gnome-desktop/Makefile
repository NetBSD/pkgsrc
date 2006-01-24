# $NetBSD: Makefile,v 1.46 2006/01/24 07:32:51 wiz Exp $
#

DISTNAME=		gnome-desktop-2.12.2
PKGREVISION=		1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-desktop/2.12/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Common GNOME2 desktop files and libgnome-desktop library

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl:run pkg-config
USE_LIBTOOL=		yes

BUILDLINK_DEPENDS.glib2+=	glib2>=2.8.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
