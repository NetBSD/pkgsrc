# $NetBSD: Makefile,v 1.7 2004/05/07 01:14:50 xtraeme Exp $
#

DISTNAME=	NovaWM-0.8_alpha
PKGNAME=	novawm-0.8
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=novawm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://novawm.sourceforge.net/
COMMENT=	Nova window manager

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
