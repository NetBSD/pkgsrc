# $NetBSD: Makefile,v 1.6 2004/10/18 02:14:08 ben Exp $
#

DISTNAME=	wmi-10
CATEGORIES=	wm
MASTER_SITES=	http://download.berlios.de/wmi/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://wmi.modprobe.de/
COMMENT=	Minimalist, flexible and highly customizable window manager

USE_BUILDLINK3=	yes
USE_LANGUAGES=	c c++
USE_X11=	yes
GNU_CONFIGURE=	yes

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
