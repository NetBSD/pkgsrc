# $NetBSD: Makefile,v 1.7 2005/06/26 18:45:44 jmmv Exp $

DISTNAME=	gnotime-2.2.1
PKGREVISION=	1
CATEGORIES=	time gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gttr/}

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://gttr.sourceforge.net/
COMMENT=	Time tracker for GNOME2

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		gnotime.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/gtkhtml36/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
