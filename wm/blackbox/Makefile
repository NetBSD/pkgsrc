# $NetBSD: Makefile,v 1.7 2002/08/25 21:51:30 jlam Exp $
#

DISTNAME=	blackbox-0.62.1
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blackboxwm/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://blackboxwm.sourceforge.net/
COMMENT=	small and fast X11R6 window manager

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-kde

.include "../../mk/bsd.pkg.mk"
