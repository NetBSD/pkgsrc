# $NetBSD: Makefile,v 1.8 2014/10/09 14:07:16 wiz Exp $
#

DISTNAME=		Xlt-13.0.13
PKGNAME=		${DISTNAME:S/Xlt/xlt/}
PKGREVISION=		3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xlt/}

MAINTAINER=		christos@NetBSD.org
HOMEPAGE=		http://xlt.sourceforge.net/
COMMENT=		OpenMotif/Lesstif Widget library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

LDFLAGS.SunOS+=		-lresolv  -lsocket   -lnsl

.include "../../mk/bsd.prefs.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
