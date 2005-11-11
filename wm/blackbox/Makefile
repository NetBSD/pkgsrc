# $NetBSD: Makefile,v 1.23 2005/11/11 18:50:25 tonio Exp $
#

DISTNAME=	blackbox-0.70.0
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blackboxwm/}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://blackboxwm.sourceforge.net/
COMMENT=	Small and fast X11R6 window manager

DEPENDS=	bsetroot>=0.2:../../wm/bsetroot

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
USE_TOOLS+=     pkg-config

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
