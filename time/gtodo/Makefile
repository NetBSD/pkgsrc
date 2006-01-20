# $NetBSD: Makefile,v 1.10 2006/01/20 16:15:54 jmmv Exp $
#

DISTNAME=	gtodo-0.14
PKGREVISION=	3
CATEGORIES=	time gnome
MASTER_SITES=	http://download.qballcow.nl/programs/gtodo/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://qballcow.nl/index.php?s=4
COMMENT=	To-do list manager for the GNOME desktop

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	YES

GCONF2_SCHEMAS=		gtodo.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
