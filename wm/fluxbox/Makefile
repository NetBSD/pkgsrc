# $NetBSD: Makefile,v 1.1.1.1 2002/01/04 02:05:33 jmcneill Exp $
#

DISTNAME=	fluxbox-0.1.5
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fluxbox/}

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://fluxbox.sourceforge.net/
COMMENT=	Window Manager for X based on Blackbox

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-kde
CONFLICTS=		blackbox-*

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
