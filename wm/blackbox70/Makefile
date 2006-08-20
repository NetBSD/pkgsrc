# $NetBSD: Makefile,v 1.1 2006/08/20 23:07:17 jschauma Exp $
#

DISTNAME=	blackbox-0.70.1
PKGNAME=	blackbox70-0.70.1
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blackboxwm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://blackboxwm.sourceforge.net/
COMMENT=	Small and fast X11R6 window manager

CONFLICTS=	bsetroot-*
CONFLICTS+=	blackbox-*

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
USE_TOOLS+=     pkg-config

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
