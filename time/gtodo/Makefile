# $NetBSD: Makefile,v 1.11 2006/01/24 07:32:39 wiz Exp $
#

DISTNAME=	gtodo-0.14
PKGREVISION=	4
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
