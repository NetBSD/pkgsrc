# $NetBSD: Makefile,v 1.19 2004/10/03 00:18:22 tv Exp $
#

DISTNAME=	blackbox-0.65.0
PKGREVISION=	5
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blackboxwm/}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://blackboxwm.sourceforge.net/
COMMENT=	Small and fast X11R6 window manager

DEPENDS=	bsetroot>=0.1nb1:../../wm/bsetroot

USE_BUILDLINK3=	YES
USE_GCC_SHLIB=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
