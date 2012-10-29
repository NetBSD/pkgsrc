# $NetBSD: Makefile,v 1.32 2012/10/29 05:07:22 asau Exp $

DISTNAME=	xsnow-1.42
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	http://dropmix.xs4all.nl/rick/Xsnow/

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://dropmix.xs4all.nl/rick/Xsnow/
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
.include "../../mk/bsd.pkg.mk"
