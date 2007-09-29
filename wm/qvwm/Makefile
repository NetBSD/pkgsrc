# $NetBSD: Makefile,v 1.32 2007/09/29 12:11:35 obache Exp $
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
USE_TOOLS+=	gmake rm lex
CONFIGURE_ENV+=	PATH_RM=${TOOLS_RM:Q}
USE_LANGUAGES=	c c++

post-install:
	${MV} ${PREFIX}/${PKGMANDIR}/man1/qvwm.1x ${PREFIX}/${PKGMANDIR}/man1/qvwm.1

.include "options.mk"
.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
