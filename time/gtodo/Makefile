# $NetBSD: Makefile,v 1.1.1.1 2004/03/10 19:20:45 jmmv Exp $
#

DISTNAME=	gtodo-0.14
CATEGORIES=	time gnome
MASTER_SITES=	http://download.qballcow.nl/programs/gtodo/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://qballcow.nl/index.php?s=4
COMMENT=	To-do list manager for the GNOME desktop

DEPENDS+=		xdg-dirs>=1.1:../../misc/xdg-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	YES

GCONF2_SCHEMAS=		gtodo.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
