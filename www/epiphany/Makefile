# $NetBSD: Makefile,v 1.12 2004/03/08 19:40:43 jmmv Exp $
#

DISTNAME=	epiphany-1.0.7
PKGREVISION=	6
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/epiphany/1.0/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/epiphany/
COMMENT=	The web browser for the GNOME Desktop

BUILD_USES_MSGFMT=	YES
DEPENDS+=		gnome2-dirs>=1.5:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

GCONF2_SCHEMAS=		epiphany.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/mozilla-gtk2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
