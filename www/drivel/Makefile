# $NetBSD: Makefile,v 1.5 2004/09/24 08:59:12 jmmv Exp $
#

DISTNAME=	drivel-1.2.1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=drivel/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.dropline.net/drivel/
COMMENT=	LiveJournal client for the GNOME Desktop

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	YES

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
