# $NetBSD: Makefile,v 1.5 2004/01/24 15:18:32 grant Exp $
#

DISTNAME=	NovaWM-0.8_alpha
PKGNAME=	novawm-0.8
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=novawm/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://novawm.sourceforge.net/
COMMENT=	Nova window manager

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
