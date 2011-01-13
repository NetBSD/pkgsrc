# $NetBSD: Makefile,v 1.39 2011/01/13 13:39:34 wiz Exp $
#

DISTNAME=	qvwm-1.1.12
PKGREVISION=	12
CATEGORIES=	wm
MASTER_SITES=	http://www.csg.is.titech.ac.jp/~kourai/qvwm/archive/qvwm/ \
		ftp://ftp.chg.ru/pub/X11/windowmanagers/qvwm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.csg.is.titech.ac.jp/~kourai/qvwm/
COMMENT=	Windows 95/98/NT like window manager for X11

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake rm lex
CONFIGURE_ENV+=	PATH_RM=${TOOLS_RM:Q}
USE_LANGUAGES=	c c++

# It cant find it for some reason
CONFIGURE_ARGS+=	--with-imlib

post-install:
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/qvwm.1x ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/qvwm.1

.include "options.mk"
.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
