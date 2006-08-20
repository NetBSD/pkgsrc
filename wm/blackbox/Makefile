# $NetBSD: Makefile,v 1.27 2006/08/20 23:08:44 jschauma Exp $
#

DISTNAME=	blackbox-0.65.0
PKGREVISION=	6
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blackboxwm/}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://blackboxwm.sourceforge.net/
COMMENT=	Small and fast X11R6 window manager

DEPENDS+=	bsetroot>=0.1nb1:../../wm/bsetroot

CONFLICTS+=	blackbox70>=0.70.1

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
