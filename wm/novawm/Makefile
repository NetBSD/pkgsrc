# $NetBSD: Makefile,v 1.3 2003/01/20 20:40:54 schmonz Exp $
#

DISTNAME=	NovaWM-0.8_alpha
PKGNAME=	novawm-0.8
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=novawm/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://novawm.sourceforge.net/
COMMENT=	Nova window manager

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
