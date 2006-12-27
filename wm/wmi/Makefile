# $NetBSD: Makefile,v 1.14 2006/12/27 13:37:41 joerg Exp $
#

DISTNAME=	wmi-10
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	http://wmii.de/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wmii.de/
COMMENT=	Minimalist, flexible and highly customizable window manager

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
