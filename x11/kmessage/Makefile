# $NetBSD: Makefile,v 1.3 2003/12/24 09:53:50 jmmv Exp $

DISTNAME=	kmessage-0.1
PKGREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	http://soliton.wins.uva.nl/~wijnhout/kmessage/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://soliton.wins.uva.nl/~wijnhout/kmessage/
COMMENT= 	KMessage is an xmessage clone for KDE

USE_BUILDLINK2=		YES
USE_GMAKE=              YES
GNU_CONFIGURE=          YES

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
