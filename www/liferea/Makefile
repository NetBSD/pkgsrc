# $NetBSD: Makefile,v 1.3 2004/06/20 20:22:12 minskim Exp $

DISTNAME=		liferea-0.5.0
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=liferea/}

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://liferea.sourceforge.net/
COMMENT=		Simple FeedReader clone for reading RSS/RDF feeds

GNU_CONFIGURE=          yes
USE_BUILDLINK3=         yes
USE_GNU_TOOLS+=		make
USE_X11=                yes
USE_PKGLOCALEDIR=	yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
