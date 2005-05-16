# $NetBSD: Makefile,v 1.12 2005/05/16 01:15:33 jlam Exp $

DISTNAME=	ethemes-0.1
PKGREVISION=	2
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://themes.org/pub/themes/e/
DISTFILES=	${E_THEMES}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://e.themes.org/
COMMENT=	Themes for the window manager Enlightenment

DEPENDS+=	enlightenment>=0.16.2:../../wm/enlightenment

DIST_SUBDIR=	ethemes
USE_X11=	yes
NO_BUILD=	yes
NO_CONFIGURE=	yes
EXTRACT_ONLY=

PKGSRC_USE_TOOLS+=	gtar

E_DATADIR=	share/enlightenment/themes

.include "../../mk/bsd.prefs.mk"

E_THEMES?=	Absolute_E-DR16-199911060830.etheme \
	ApplePlatinum-DR16-200001161300.etheme \
	BevelFree-DR16-199908221339.etheme Black-DR16-199911201455.etheme \
	E-Tech_Hydro-DR16-199912241355.etheme Ebench-DR16-199911181110.etheme \
	Evisio-Green-DR16-199908220707.etheme \
	FinalE-DR16-200003121555.etheme \
	GTK+-DR16-200004271913.etheme \
	HackerPurple138-DR16-199908131917.etheme \
	IReX-DR16-199912221118.etheme Industrial-DR16-199910202053.etheme \
	Sensible-DR16-199908211837.etheme Sunset-DR16-200001061225.etheme \
	X11-DR16-199910131422.etheme \
	arctic-DR16-200006050720.etheme \
	eMac-DR16-199912101635.etheme small-e-DR16-199908230041.etheme

do-install:
.for FILE in ${E_THEMES}
	NAME=`echo ${FILE} | ${SED} -e s/-DR16.*//` ; \
	${INSTALL_DATA_DIR} ${PREFIX}/${E_DATADIR}/$$NAME ; \
	${GTAR} -C ${PREFIX}/${E_DATADIR}/$$NAME \
		-xzf ${DISTDIR}/${DIST_SUBDIR}/${FILE}
.endfor
.for DIR in Absolute_E ApplePlatinum FinalE
	cd ${PREFIX}/${E_DATADIR}/${DIR} \
		&& ${CHMOD} go+rx `${FIND} . -type d -print` \
		&& ${CHMOD} go+r `${FIND} . -type f -print`
.endfor

.include "../../mk/bsd.pkg.mk"
