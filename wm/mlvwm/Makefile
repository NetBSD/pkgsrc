# $NetBSD: Makefile,v 1.12 2019/05/23 19:23:19 rillig Exp $
#

DISTNAME=	mlvwm091
PKGNAME=	mlvwm-0.9.1
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	http://www2u.biglobe.ne.jp/~y-miyata/mlvwm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www2u.biglobe.ne.jp/~y-miyata/mlvwm.html
COMMENT=	Macintosh Like Virtual Window Manager

USE_IMAKE=	yes

EGDIR=			${PREFIX}/share/examples/mlvwm
INSTALLATION_DIRS=	share/doc/mlvwm share/examples/mlvwm share/mlvwm

post-install:
.for f in README CONFIGURATION
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/mlvwm
.endfor
.for f in Mlvwmrc Mlvwmrc-Xterm
	${INSTALL_DATA} ${WRKSRC}/sample_rc/${f} ${DESTDIR}${EGDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/pixmap/*.xpm ${DESTDIR}${PREFIX}/share/mlvwm

SUBST_CLASSES+=		xpm
SUBST_STAGE.xpm=	post-configure
SUBST_FILES.xpm=	sample_rc/Mlvwmrc
SUBST_VARS.xpm=		PREFIX
SUBST_MESSAGE.xpm=	Fixing configuration file.

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
