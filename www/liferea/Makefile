# $NetBSD: Makefile,v 1.2 2004/06/11 18:03:58 minskim Exp $

DISTNAME=		liferea-0.3.3
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=liferea/}

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://liferea.sourceforge.net/
COMMENT=		Simple FeedReader clone for reading RSS/RDF feeds

GNU_CONFIGURE=          yes
USE_BUILDLINK3=         yes
USE_GNU_TOOLS+=		make
USE_X11=                yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
