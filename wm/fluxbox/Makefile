# $NetBSD: Makefile,v 1.2 2002/04/22 18:39:18 wiz Exp $
#

DISTNAME=	fluxbox-0.1.8
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

GCC_VERSION!=		gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs)
.include "../../lang/gcc/Makefile.gcc"
.endif

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
