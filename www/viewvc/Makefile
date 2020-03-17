# $NetBSD: Makefile,v 1.36 2020/03/17 22:14:15 wiz Exp $

DISTNAME=	viewvc-1.2.0
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_GITHUB:=viewvc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.viewvc.org/
COMMENT=	Viewing the content of CVS/SVN repositories with a Webbrowser
LICENSE=	2-clause-bsd

REPLACE_PYTHON=	viewvc-install bin/* bin/cgi/*.cgi lib/*.py
# https://github.com/viewvc/viewvc/issues/138
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.1.27

.if !exists(/usr/bin/rlog)
DEPENDS+=	rcs-[0-9]*:../../devel/rcs
RCS_PKG=	YES
.else
RCS_PKG=	NO
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
SUBST_STAGE.conf=	pre-configure
SUBST_MESSAGE.conf=	Fixing configuration files.
SUBST_FILES.conf=	conf/viewvc.conf.dist
SUBST_FILES.conf+=	conf/cvsgraph.conf.dist
SUBST_VARS.conf=	VIEWVCDIR
SUBST_VARS.conf+=	PREFIX
SUBST_VARS.conf+=	PHP_OPT
SUBST_VARS.conf+=	CVSGRAPH_OPT

.if defined(RCS_PKG) && ${RCS_PKG} == "YES"
SUBST_SED.conf+=	-e "s|@RCS_PREFIX@|${PREFIX}|g"
.else
SUBST_SED.conf+=	-e "s|@RCS_PREFIX@|/usr|g"
.endif

CHECK_PORTABILITY_SKIP=	tools/make-release

INSTALLATION_DIRS=	share/examples/viewvc

do-install:
	(cd ${WRKSRC} && \
		${PYTHONBIN} \
		viewvc-install --prefix=${PREFIX}/${VIEWVCDIR} --destdir=${DESTDIR})

	${INSTALL_DATA} ${WRKSRC}/conf/viewvc.conf.dist \
		${DESTDIR}${PREFIX}/share/examples/viewvc/viewvc.conf
	${INSTALL_DATA} ${WRKSRC}/conf/cvsgraph.conf.dist \
		${DESTDIR}${PREFIX}/share/examples/viewvc/cvsgraph.conf

post-install:
	${CHMOD} ${SHAREMODE} \
		${DESTDIR}/${PREFIX}/share/viewvc/bin/mod_python/.htaccess
	${CHMOD} ${SHAREMODE} \
		${DESTDIR}/${PREFIX}/share/viewvc/bin/mod_python/*.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
