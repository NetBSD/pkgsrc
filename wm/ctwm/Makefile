# $NetBSD: Makefile,v 1.13 2004/03/10 14:12:51 xtraeme Exp $
#

DISTNAME=	ctwm-3.6
CATEGORIES=	x11 wm
MASTER_SITES=	http://ctwm.free.lp.se/dist/
# XXX: 3.6 didn't include the XPMs, XPM tarball generated from 3.5.2 manually
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-xpm${EXTRACT_SUFX}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ctwm.free.lp.se/
COMMENT=	Window manager with support for multiple virtual screens and GNOME 1.x

USE_BUILDLINK3=	YES
USE_IMAKE=	YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
