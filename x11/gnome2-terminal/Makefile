# $NetBSD: Makefile,v 1.36 2005/03/22 16:20:49 jmmv Exp $
#

DISTNAME=		gnome-terminal-2.10.0
PKGNAME=		${DISTNAME:S/-/2-/}
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-terminal/2.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Xterm like terminal program for GNOME 2

BUILD_USES_MSGFMT=	YES

CONFLICTS=		gnome-core-[0-9]*

USE_PERL5=		build
GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_X11=		YES
USE_LIBTOOL=		YES

GCONF2_SCHEMAS= 	gnome-terminal.schemas

BUILDLINK_DEPENDS.startup-notification+=	startup-notification>=0.8

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libzvt/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
