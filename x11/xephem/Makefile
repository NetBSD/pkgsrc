# $NetBSD: Makefile,v 1.8 2001/02/17 17:07:06 wiz Exp $

DISTNAME=	xephem-3.4
CATEGORIES=	x11
MASTER_SITES=	http://www.clearskyinstitute.com/xephem/ \
		ftp://iraf.noao.edu/contrib/xephem/ \
		ftp://star.rl.ac.uk/pub/iraf/contrib/xephem/ \
		ftp://iphcip1.physik.uni-mainz.de/pub/xephem/ \
		ftp://ecf.hq.eso.org/iraf/contrib/xephem/ \
		ftp://sinobu.mtk.nao.ac.jp/NOAO/contrib/xephem/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.clearskyinstitute.com/xephem/
COMMENT=	Interactive astronomical ephemeris program

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
	${SED} s,@PREFIX@,${PREFIX}, ${FILESDIR}/XEphem.ad > ${WRKDIR}/XEphem
	${INSTALL_DATA} ${WRKDIR}/XEphem ${PREFIX}/lib/X11/app-defaults
	${MKDIR} ${PREFIX}/share/xephem/tools
	(cd ${WRKSRC}; ${CP} -R auxil catalogs fifos fits \
	 ${PREFIX}/share/xephem)
	(cd ${WRKSRC}/tools; ${INSTALL_DATA} README \
			${PREFIX}/share/xephem/tools; \
		${INSTALL_SCRIPT} extract.awk jost2edb.awk\
			${PREFIX}/share/xephem/tools)
	(cd ${WRKSRC}/tools; for file in ${PERL_SCRIPTS}; do \
		${SED} 1s,@LOCALBASE@,${LOCALBASE}, $$file \
			> ${WRKDIR}/$$file; \
		${INSTALL_SCRIPT} ${WRKDIR}/$$file \
			${PREFIX}/share/xephem/tools; \
	done)
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/xephem

.include "../../mk/bsd.pkg.mk"
