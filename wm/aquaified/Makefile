# $NetBSD: Makefile,v 1.1.1.1 2002/10/05 22:10:41 mrg Exp $

DISTNAME=	aquaified-0.30
CATEGORIES=	x11 wm
MASTER_SITES=	http://download.freshmeat.net/themes/aquaified/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://themes.freshmeat.net/projects/aquaified/
COMMENT=	Aquaified is a theme for the Sawfish window manager.

DEPENDS+=	sawfish:../../wm/sawfish

NO_BUILD=	yes
NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}

PLIST_SRC=	${WRKDIR}/PLIST
THEME_DATADIR=	share/sawfish/themes
INST_DATADIR=	${PREFIX}/${THEME_DATADIR}

.include "../../mk/bsd.prefs.mk"

do-install:
	@${RM} -f ${PLIST_SRC}
	@${TOUCH} ${PLIST_SRC}
	@${MKDIR} ${INST_DATADIR}/Aquaified
	${ECHO} "Installing Aquaified in ${INST_DATADIR}.";
	cd ${WRKSRC}/Aquaified; for FILE in *; do \
	    ${INSTALL_DATA} "$$FILE" ${INST_DATADIR}/Aquaified; \
	    ${ECHO} "${THEME_DATADIR}/Aquaified/$$FILE" >>${PLIST_SRC}; \
	done
	@${ECHO} "@dirrm ${THEME_DATADIR}/Aquaified" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
