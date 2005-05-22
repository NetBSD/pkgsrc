# $NetBSD: Makefile,v 1.9 2005/05/22 20:08:43 jlam Exp $
#

DISTNAME=	NovaWM-0.8_alpha
PKGNAME=	novawm-0.8
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=novawm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://novawm.sourceforge.net/
COMMENT=	Nova window manager

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
USE_X11=	YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
