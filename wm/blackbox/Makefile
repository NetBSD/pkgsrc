# $NetBSD: Makefile,v 1.6 2002/03/14 15:07:01 wiz Exp $
#

DISTNAME=	blackbox-0.62.1
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blackboxwm/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://blackboxwm.sourceforge.net/
COMMENT=	small and fast X11R6 window manager

USE_BUILDLINK_ONLY=	yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-kde

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
