# $NetBSD: Makefile,v 1.1.1.1 2001/05/30 14:30:48 agc Exp $
# FreeBSD Id: ports/x11-wm/qvwm/Makefile,v 1.40 2001/04/02 05:04:18 mharo Exp

DISTNAME=	qvwm-1.1.10
CATEGORIES=	wm
MASTER_SITES=	ftp://www.qvwm.org/pub/qvwm/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.qvwm.org/
COMMENT=	Windows 95/98/NT like window manager for X11

DEPENDS+=	esound-*:../../audio/esound
DEPENDS+=	imlib-*:../../graphics/imlib

USE_X11BASE=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
