# $NetBSD: Makefile,v 1.10 2003/01/05 20:10:10 jschauma Exp $
#

DISTNAME=	blackbox-0.65.0
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blackboxwm/}

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://blackboxwm.sourceforge.net/
COMMENT=	small and fast X11R6 window manager

DEPENDS+=	bsetroot>=0.1nb1:../../wm/bsetroot

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
