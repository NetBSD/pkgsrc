# $NetBSD: Makefile,v 1.2 2003/12/13 00:45:27 wiz Exp $
#

DISTNAME=	zenity-1.6
PKGREVISION=	1
CATEGORIES=	x11 gnome2
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/zenity/1.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Display GNOME dialogs from the command line

DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../textproc/intltool/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
