# $NetBSD: Makefile,v 1.11 2005/04/11 21:48:11 tv Exp $

DISTNAME=	kmessage-0.1
PKGREVISION=	5
CATEGORIES=	x11 kde
MASTER_SITES=	http://soliton.wins.uva.nl/~wijnhout/kmessage/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://soliton.wins.uva.nl/~wijnhout/kmessage/
COMMENT= 	KMessage is an xmessage clone for KDE

USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=          YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
