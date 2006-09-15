# $NetBSD: Makefile,v 1.58 2006/09/15 15:18:02 jmmv Exp $
#

DISTNAME=		gnome-terminal-2.16.0
PKGNAME=		${DISTNAME:S/-/2-/}
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-terminal/2.16/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Xterm like terminal program for GNOME 2

CONFLICTS=		gnome-core-[0-9]*

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

GCONF2_SCHEMAS= 	gnome-terminal.schemas

BUILDLINK_API_DEPENDS.gtk2+=			gtk2+>=2.10.0
BUILDLINK_API_DEPENDS.startup-notification+=	startup-notification>=0.8

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libzvt/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
