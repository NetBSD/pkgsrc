# $NetBSD: Makefile,v 1.15 2003/07/21 17:34:00 martti Exp $
#

DISTNAME=	blackbox-0.65.0
PKGREVISION=	4
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blackboxwm/}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://blackboxwm.sourceforge.net/
COMMENT=	Small and fast X11R6 window manager

DEPENDS=	bsetroot>=0.1nb1:../../wm/bsetroot

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

.include "../../devel/gettext-lib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
