# $NetBSD: Makefile,v 1.3 1998/09/02 08:46:24 frueauf Exp $

DISTNAME=	xephem-3.1
CATEGORIES=	x11
MASTER_SITES=	ftp://iraf.noao.edu/contrib/xephem/xephem-3.1/ \
		ftp://gastro23.physics.uiowa.edu/pub/xephem/ \
		ftp://iphcip1.physik.uni-mainz.de/pub/xephem/ \
		ftp://wolf.ifj.edu.pl/mirror/xephem/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://iraf.noao.edu/~ecdowney/xephem.html

DEPENDS+=	xpm-3.4k:../../graphics/xpm

WRKSRC=		${WRKDIR}/${DISTNAME}/GUI/xephem
LIBSRC=		${WRKDIR}/${DISTNAME}/libastro
USE_PERL5=	yes
USE_IMAKE=	yes
USE_MOTIF=	yes

LICENSE=	non-commercial-use

pre-configure:
	@(cd ${LIBSRC} && ${SETENV} ${SCRIPTS_ENV} XPROJECTROOT=${X11BASE} \
		${XMKMF})

pre-build:
	@(cd ${LIBSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
		-f ${MAKEFILE} ${ALL_TARGET})

PERL_SCRIPTS= astorb2edb.pl encke2edb.pl yeomans.pl

post-install:
	@${SED} s,@PREFIX@,${PREFIX}, ${WRKSRC}/XEphem.ad > ${WRKDIR}/XEphem
	${INSTALL_DATA} ${WRKDIR}/XEphem ${PREFIX}/lib/X11/app-defaults
	@${INSTALL_DATA_DIR} ${PREFIX}/share/xephem/auxil \
		${PREFIX}/share/xephem/catalogs \
		${PREFIX}/share/xephem/tools \
		${PREFIX}/share/doc/xephem
	(cd ${WRKSRC}/auxil; ${INSTALL_DATA} README mars_db marsmap.fts \
		moon.fts moon_db xephem.hlp xephem_sites \
		${PREFIX}/share/xephem/auxil)
	(cd ${WRKSRC}/catalogs; ${INSTALL_DATA} Messier.edb NGC.edb SAC.edb \
		YBS.edb asteroids.edb comets.edb mir.edb \
		${PREFIX}/share/xephem/catalogs)
	(cd ${WRKSRC}/tools; ${INSTALL_DATA} README gps.awk jost2edb.nawk \
			${PREFIX}/share/xephem/tools; \
		${INSTALL_SCRIPT} extract.awk tle2edb.awk \
			${PREFIX}/share/xephem/tools)
	@(cd ${WRKSRC}/tools; for file in ${PERL_SCRIPTS}; do \
		${SED} 1s,@LOCALBASE@,${LOCALBASE}, $$file \
			> ${WRKDIR}/$$file; \
	done)
	for file in ${PERL_SCRIPTS}; do \
		${INSTALL_SCRIPT} ${WRKDIR}/$$file \
			${PREFIX}/share/xephem/tools; \
	done
	(cd ${WRKDIR}/${DISTNAME}; ${INSTALL_DATA} Copyright README \
		${PREFIX}/share/doc/xephem)

.include "../../mk/bsd.pkg.mk"
