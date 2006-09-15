# $NetBSD: Makefile,v 1.40 2006/09/15 15:19:22 jmmv Exp $
#

DISTNAME=	zenity-2.16.0
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/zenity/2.16/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Display GNOME dialogs from the command line

USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
