# $NetBSD: Makefile,v 1.9 2004/10/03 00:18:26 tv Exp $

DISTNAME=		liferea-0.5.3
PKGREVISION=	1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=liferea/}

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://liferea.sourceforge.net/
COMMENT=		Simple FeedReader clone for reading RSS/RDF feeds

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	libtool
USE_GNU_TOOLS+=		make
USE_X11=		yes
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
