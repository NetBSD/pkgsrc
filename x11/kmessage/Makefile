# $NetBSD: Makefile,v 1.22 2008/01/18 05:10:06 tnn Exp $

DISTNAME=	kmessage-0.1
PKGREVISION=	13
CATEGORIES=	x11 kde
MASTER_SITES=	http://soliton.wins.uva.nl/~wijnhout/kmessage/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://soliton.wins.uva.nl/~wijnhout/kmessage/
COMMENT=	KMessage is an xmessage clone for KDE

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
