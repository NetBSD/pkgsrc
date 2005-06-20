# $NetBSD: Makefile,v 1.20 2005/06/20 17:02:04 kristerw Exp $
#

DISTNAME=	qvwm-1.1.12
PKGREVISION=	5
CATEGORIES=	wm
MASTER_SITES=	ftp://www.qvwm.org/pub/qvwm/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.qvwm.org/
COMMENT=	Windows 95/98/NT like window manager for X11

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake rm
CONFIGURE_ENV+=	ac_cv_path_PATH_RM="${TOOLS_RM}"
USE_LANGUAGES=	c++

post-install:
	${MV} ${PREFIX}/man/man1/qvwm.1x ${PREFIX}/man/man1/qvwm.1

.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
