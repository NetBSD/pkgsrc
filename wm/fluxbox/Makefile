# $NetBSD: Makefile,v 1.5 2002/11/10 19:36:57 jmcneill Exp $
#

DISTNAME=	fluxbox-0.1.12
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fluxbox/}

MAINTAINER=	jmcneill@netbsd.org
HOMEPAGE=	http://fluxbox.sourceforge.net/
COMMENT=	Window Manager for X based on Blackbox

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_CXX=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-kde
CONFLICTS=		blackbox-*

.include "../../lang/gcc/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
