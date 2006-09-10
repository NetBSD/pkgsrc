# $NetBSD: Makefile,v 1.20 2006/09/10 19:57:28 schwarz Exp $

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

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
