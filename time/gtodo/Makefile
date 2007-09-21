# $NetBSD: Makefile,v 1.23 2007/09/21 13:04:24 wiz Exp $
#

DISTNAME=	gtodo-0.14
PKGREVISION=	12
CATEGORIES=	time gnome
MASTER_SITES=	http://download.qballcow.nl/programs/gtodo/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cms.qballcow.nl/index.php?page=Gnome_Task_List_Manager
COMMENT=	To-do list manager for the GNOME desktop

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	YES

GCONF_SCHEMAS=		gtodo.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
