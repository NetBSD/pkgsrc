# $NetBSD: Makefile,v 1.16 2007/12/10 13:25:58 obache Exp $
#

DISTNAME=	wmi-10
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	http://www.suckless.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.suckless.org/wiki/wmii/download
COMMENT=	Minimalist, flexible and highly customizable window manager

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
