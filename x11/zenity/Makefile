# $NetBSD: Makefile,v 1.27 2006/01/24 07:33:02 wiz Exp $
#

DISTNAME=	zenity-2.12.1
PKGREVISION=	1
CATEGORIES=	x11 gnome2
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/zenity/2.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Display GNOME dialogs from the command line

BUILD_USES_MSGFMT=	yes

USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

BUILDLINK_DEPENDS.glib2+=	glib2>=2.8.0

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
