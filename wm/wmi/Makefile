# $NetBSD: Makefile,v 1.4 2004/07/01 16:28:33 seb Exp $
#

DISTNAME=	wmi-8
PKGREVISION=	1
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
