# $NetBSD: Makefile,v 1.10 2004/04/23 12:07:12 markd Exp $

DISTNAME=	kimagemapeditor-1.0
PKGREVISION=	4
CATEGORIES=	www kde
MASTER_SITES=	http://savannah.nongnu.org/download/kimagemap/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/kimagemap/
COMMENT= 	Edit HTML Image maps

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
