# $NetBSD: Makefile,v 1.46 2006/01/24 07:32:52 wiz Exp $
#

DISTNAME=		gnome-terminal-2.12.0
PKGNAME=		${DISTNAME:S/-/2-/}
PKGREVISION=		2
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-terminal/2.12/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Xterm like terminal program for GNOME 2

BUILD_USES_MSGFMT=	YES

CONFLICTS=		gnome-core-[0-9]*

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_MSGFMT_PLURALS=	YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake perl pkg-config
USE_LIBTOOL=		YES

GCONF2_SCHEMAS= 	gnome-terminal.schemas

BUILDLINK_DEPENDS.startup-notification+=	startup-notification>=0.8

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libzvt/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
