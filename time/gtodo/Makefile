# $NetBSD: Makefile,v 1.67 2018/11/14 22:22:32 kleink Exp $
#

DISTNAME=	gtodo-0.14
PKGREVISION=	51
CATEGORIES=	time gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtodo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.sarine.nl/gnome-task-list-manager
COMMENT=	To-do list manager for the GNOME desktop

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	YES

GCONF_SCHEMAS=		gtodo.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
