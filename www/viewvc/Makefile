# $NetBSD: Makefile,v 1.4 2008/01/24 07:23:47 obache Exp $
#

DISTNAME=	viewvc-1.0.4
CATEGORIES=	devel www
MASTER_SITES=	http://viewvc.tigris.org/files/documents/3330/37319/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.viewvc.org/
COMMENT=	Viewing the content of CVS/SVN repositories with a Webbrowser

PYTHON_PATCH_SCRIPTS=	viewvc-install bin/* bin/cgi/*.cgi lib/*.py

.if !exists(/usr/bin/rlog)
DEPENDS+=	rcs-[0-9]*:../../devel/rcs
.endif

NO_BUILD=	YES
VIEWVCDIR=	share/viewvc
PLIST_SUBST+=	VIEWVCDIR=${VIEWVCDIR:Q}

CONF_FILES=	${PREFIX}/share/examples/viewvc/viewvc.conf \
		${PREFIX}/${VIEWVCDIR:Q}/viewvc.conf
CONF_FILES+=	${PREFIX}/share/examples/viewvc/cvsgraph.conf \
		${PREFIX}/${VIEWVCDIR:Q}/cvsgraph.conf

.include "options.mk"

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_MESSAGE.conf=	Fixing configuration files.
SUBST_FILES.conf=	viewvc.conf.dist
SUBST_SED.conf=		-e "s|@VIEWVCDIR@|${VIEWVCDIR}|g"
SUBST_SED.conf+=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_SED.conf+=	-e "s|@PHP_OPT@|${PHP_OPT}|g"
SUBST_SED.conf+=	-e "s|@CVSGRAPH_OPT@|${CVSGRAPH_OPT}|g"

CHECK_PORTABILITY_SKIP=	tools/make-release

do-install:
	(cd ${WRKSRC} && \
		${PYTHONBIN} \
		viewvc-install --prefix=${PREFIX}/${VIEWVCDIR} --destdir="")

	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/viewvc
	${INSTALL_DATA} ${WRKSRC}/viewvc.conf.dist \
		${PREFIX}/share/examples/viewvc/viewvc.conf
	${INSTALL_DATA} ${WRKSRC}/cvsgraph.conf.dist \
		${PREFIX}/share/examples/viewvc/cvsgraph.conf

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
