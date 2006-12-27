# $NetBSD: Makefile,v 1.22 2006/12/27 13:37:46 joerg Exp $

DISTNAME=	xsnow-1.42
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.euronet.nl/~rja/Xsnow/

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://www.euronet.nl/~rja/Xsnow/
COMMENT=	Create a snowy and Santa-y desktop

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if !empty(LOWER_OPSYS:Mirix5*)
# needs snprintf()
. include "../../pkgtools/libnbcompat/buildlink3.mk"
IMAKEOPTS+=     -DExtraLibraries=${BUILDLINK_LDADD.libnbcompat:Q}
.endif

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
