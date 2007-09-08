# $NetBSD: Makefile,v 1.25 2007/09/08 21:58:02 jlam Exp $

DISTNAME=	xsnow-1.42
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.euronet.nl/~rja/Xsnow/

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://www.euronet.nl/~rja/Xsnow/
COMMENT=	Create a snowy and Santa-y desktop

USE_FEATURES=	snprintf
USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if !empty(MISSING_FEATURES:Msnprintf)
IMAKEOPTS+=	-DExtraLibraries=${LIBS:Q}
.endif

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
