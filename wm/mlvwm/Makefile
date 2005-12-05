# $NetBSD: Makefile,v 1.2 2005/12/05 20:51:09 rillig Exp $
#

DISTNAME=	mlvwm091
PKGNAME=	mlvwm-0.9.1
CATEGORIES=	wm
MASTER_SITES=	http://www2u.biglobe.ne.jp/~y-miyata/mlvwm/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www2u.biglobe.ne.jp/~y-miyata/mlvwm/
COMMENT=	Macintosh Like Virtual Window Manager

USE_IMAKE=	yes

EGDIR=			${PREFIX}/share/examples/mlvwm
INSTALLATION_DIRS=	share/doc/mlvwm share/examples/mlvwm share/mlvwm

post-install:
.for f in README CONFIGURATION
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/mlvwm
.endfor
.for f in Mlvwmrc Mlvwmrc-Xterm
	${INSTALL_DATA} ${WRKSRC}/sample_rc/${f} ${EGDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/pixmap/*.xpm ${PREFIX}/share/mlvwm

SUBST_CLASSES+=		xpm
SUBST_STAGE.xpm=	post-configure
SUBST_FILES.xpm=	sample_rc/Mlvwmrc
SUBST_SED.xpm=		-e "s,@PREFIX@,${PREFIX},"
SUBST_MESSAGE.xpm=	"Fixing configuration file."

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
