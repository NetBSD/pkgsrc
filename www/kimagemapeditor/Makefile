# $NetBSD: Makefile,v 1.9 2004/03/26 02:27:57 wiz Exp $

DISTNAME=	kimagemapeditor-1.0
PKGREVISION=	4
CATEGORIES=	www kde
MASTER_SITES=	http://savannah.nongnu.org/download/kimagemap/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/kimagemap/
COMMENT= 	Edit HTML Image maps

USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
