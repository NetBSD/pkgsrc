# $NetBSD: Makefile,v 1.7 2004/02/14 17:21:54 jlam Exp $

DISTNAME=	kimagemapeditor-1.0
PKGREVISION=	3
CATEGORIES=	www kde
MASTER_SITES=	http://savannah.nongnu.org/download/kimagemap/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/kimagemap/
COMMENT= 	Edit HTML Image maps

USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
