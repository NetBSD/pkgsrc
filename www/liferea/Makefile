# $NetBSD: Makefile,v 1.24 2005/12/31 12:32:48 wiz Exp $

DISTNAME=		liferea-1.0-RC2
PKGNAME=		liferea-1.0rc2
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=liferea/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://liferea.sourceforge.net/
COMMENT=		Simple FeedReader clone for reading RSS/RDF feeds

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

SHLIBTOOL_OVERRIDE=	libtool

GCONF2_SCHEMAS=		liferea.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
