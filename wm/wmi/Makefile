# $NetBSD: Makefile,v 1.5 2004/10/03 00:18:23 tv Exp $
#

DISTNAME=	wmi-8
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	http://download.berlios.de/wmi/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://wmi.berlios.de/
COMMENT=	Minimalist, flexible and highly customizable window manager

USE_BUILDLINK3=	yes
USE_LANGUAGES=	c c++
USE_X11=	yes
GNU_CONFIGURE=	yes

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
