# $NetBSD: Makefile,v 1.28 2006/07/22 04:46:19 rillig Exp $
#

DISTNAME=	qvwm-1.1.12
PKGREVISION=	7
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.yz.yamagata-u.ac.jp/pub/X11/wm/qvwm/qvwm/ \
		ftp://ftp.chg.ru/pub/X11/windowmanagers/qvwm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.csg.is.titech.ac.jp/~kourai/qvwm/
COMMENT=	Windows 95/98/NT like window manager for X11

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake rm
CONFIGURE_ENV+=	PATH_RM=${TOOLS_RM:Q}
USE_LANGUAGES=	c c++

post-install:
	${MV} ${PREFIX}/man/man1/qvwm.1x ${PREFIX}/man/man1/qvwm.1

.include "options.mk"
.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
