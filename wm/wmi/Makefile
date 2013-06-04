# $NetBSD: Makefile,v 1.21 2013/06/04 22:17:14 tron Exp $
#

DISTNAME=	wmi-10
PKGREVISION=	5
CATEGORIES=	wm
MASTER_SITES=	http://www.suckless.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wmi.suckless.org/
COMMENT=	Minimalist, flexible and highly customizable window manager

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
