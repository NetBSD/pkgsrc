# $NetBSD: Makefile,v 1.6 2000/03/08 12:01:49 agc Exp $

DISTNAME=	xephem-3.2.3
CATEGORIES=	x11
MASTER_SITES=	http://www.clearskyinstitute.com/xephem/xephem/ \
		ftp://iraf.noao.edu/contrib/xephem/ \
		ftp://star.rl.ac.uk/pub/iraf/contrib/xephem/ \
		ftp://iphcip1.physik.uni-mainz.de/pub/xephem/ \
		ftp://ecf.hq.eso.org/iraf/contrib/xephem/ \
		ftp://sinobu.mtk.nao.ac.jp/NOAO/contrib/xephem/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.clearskyinstitute.com/xephem/

WRKSRC=		${WRKDIR}/${DISTNAME}/GUI/xephem
LIBSRC=		${WRKDIR}/${DISTNAME}/libastro
USE_PERL5=	yes
USE_IMAKE=	yes
USE_MOTIF=	yes

LICENSE=	no-commercial-use

pre-configure:
	@(cd ${LIBSRC} && ${SETENV} ${SCRIPTS_ENV} XPROJECTROOT=${X11BASE} \
		${XMKMF})

pre-build:
	@(cd ${LIBSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
		-f ${MAKEFILE} ${ALL_TARGET})

PERL_SCRIPTS= astorb2edb.pl mpcorb2edb.pl tle2edb.pl

post-install:
	@${SED} s,@PREFIX@,${PREFIX}, ${WRKSRC}/XEphem.ad > ${WRKDIR}/XEphem
	${INSTALL_DATA} ${WRKDIR}/XEphem ${PREFIX}/lib/X11/app-defaults
	@${MKDIR} ${PREFIX}/share/xephem/auxil \
		${PREFIX}/share/xephem/catalogs \
		${PREFIX}/share/xephem/tools \
		${PREFIX}/share/doc/xephem
	(cd ${WRKSRC}/auxil; ${INSTALL_DATA} README jupiter.9910 logo.gif \
		mars.9910 mars_db marsmap.fts \
		moon.fts moon_db saturne.9910 uranus.9910 \
		xephem.hlp xephem_sites \
		${PREFIX}/share/xephem/auxil)
	(cd ${WRKSRC}/catalogs; ${INSTALL_DATA} ISS.edb Messier.edb NGC.edb \
		SAC.edb YBS.edb asteroids.edb comets.edb hickson.edb \
		${PREFIX}/share/xephem/catalogs)
	(cd ${WRKSRC}/tools; ${INSTALL_DATA} README \
			${PREFIX}/share/xephem/tools; \
		${INSTALL_SCRIPT} extract.awk jost2edb.awk\
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
