# $NetBSD: Makefile,v 1.4 2002/10/06 00:04:02 wiz Exp $
#

DISTNAME=	aquaified-0.30
CATEGORIES=	x11 wm
MASTER_SITES=	http://download.freshmeat.net/themes/aquaified/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://themes.freshmeat.net/projects/aquaified/
COMMENT=	theme for the Sawfish window manager, similar to Aqua (MacOS X)

DEPENDS+=	sawfish>=1.0.1:../../wm/sawfish

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Aquaified

THEME_DATADIR=	share/sawfish/themes
INST_DATADIR=	${PREFIX}/${THEME_DATADIR}

do-install:
	@${INSTALL_DATA_DIR} ${INST_DATADIR}/Aquaified
	@cd ${WRKSRC} && ${INSTALL_DATA} * ${INST_DATADIR}/Aquaified

.include "../../mk/bsd.pkg.mk"
