# $NetBSD: Makefile,v 1.6 2013/01/19 23:22:54 riastradh Exp $
#

DISTNAME=		Xlt-13.0.13
PKGNAME=		${DISTNAME:S/Xlt/xlt/}
PKGREVISION=		3
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
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
