# $NetBSD: Makefile,v 1.5 2012/10/29 05:07:15 asau Exp $
#

DISTNAME=		Xlt-13.0.13
PKGNAME=		${DISTNAME:S/Xlt/xlt/}
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xlt/}

MAINTAINER=		christos@NetBSD.org
HOMEPAGE=		http://xlt.sourceforge.net/
COMMENT=		OpenMotif/Lesstif Widget library

PKG_INSTALLATION_TYPES=	overwrite

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../mk/bsd.prefs.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
