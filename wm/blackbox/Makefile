# $NetBSD: Makefile,v 1.11 2003/02/20 16:54:16 jschauma Exp $
#

DISTNAME=	blackbox-0.65.0
PKGREVISION=	2
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
