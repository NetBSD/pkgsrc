# $NetBSD: Makefile,v 1.3 2011/12/07 17:21:09 drochner Exp $
#

DISTNAME=		Xlt-13.0.13
PKGNAME=		${DISTNAME:S/Xlt/xlt/}
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xlt/}

MAINTAINER=		christos@NetBSD.org
HOMEPAGE=		http://xlt.sourceforge.net/
COMMENT=		OpenMotif/Lesstif Widget library

PKG_INSTALLATION_TYPES=	overwrite
PKG_DESTDIR_SUPPORT=	user-destdir

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
