# $NetBSD: Makefile,v 1.1.1.1 2000/01/06 23:53:32 garbled Exp $

DISTNAME=	ethemes-0.1
CATEGORIES=	x11
MASTER_SITES=	ftp://themes.org/pub/themes/e/
DIST_SUBDIR=	ethemes
DISTFILES=	${THEME_FILES}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://e.themes.org/

DEPENDS+=	enlightenment-0.16.2:../../x11/enlightenment

USE_X11BASE=	yes
NO_BUILD=	yes
NO_CONFIGURE=	yes
NO_PATCH=	yes
NO_WRKDIR=	yes
NO_EXTRACT=	yes
NO_CHECKSUM=	yes

E_DATADIR=	share/enlightenment/themes

.include "../../mk/bsd.prefs.mk"

E_THEMES?=	Absolute_E-DR16-199911060830.etheme \
	ApplePlatinum-DR16-199910201051.etheme \
	BevelFree-DR16-199908221339.etheme Black-DR16-199911201455.etheme \
	E-Tech_Hydro-DR16-199912241355.etheme Ebench-DR16-199911181110.etheme \
	Evisio-Green-DR16-199908220707.etheme \
	FinalE-DR16-199912281649.etheme GTK+-DR16-199911211511.etheme \
	HackerPurple138-DR16-199908131917.etheme \
	IReX-DR16-199912221118.etheme Industrial-DR16-199910202053.etheme \
	Sensible-DR16-199908211837.etheme Sunset-DR16-200001061137.etheme \
	X11-DR16-199910131422.etheme arctic-DR16-199912280920.etheme \
	eMac-DR16-199912101635.etheme small-e-DR16-199908230041.etheme

do-install:
.for FILE in ${E_THEMES}
	NAME=`echo ${FILE} | sed -e s/-DR16.*//` ; \
	${MKDIR} ${PREFIX}/${E_DATADIR}/$$NAME ; \
	tar -C ${PREFIX}/${E_DATADIR}/$$NAME \
		-xzf ${DISTDIR}/${DIST_SUBDIR}/${FILE}
.endfor

.include "../../mk/bsd.pkg.mk"
