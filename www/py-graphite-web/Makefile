# $NetBSD: Makefile,v 1.10 2022/01/10 22:46:03 wiz Exp $

DISTNAME=	graphite-web-0.9.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
GITHUB_PROJECT=	graphite-web
MASTER_SITES=	${MASTER_SITE_GITHUB:=graphite-project/}

MAINTAINER=	riz@NetBSD.org
HOMEPAGE=	https://launchpad.net/graphite
COMMENT=	Enterprise scalable realtime graphing platform
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-carbon>=${PKGREVISION_NOREV}:../../databases/py-carbon
DEPENDS+=	${PYPKGPREFIX}-django>=1.3.1:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-tagging>=0.3.1:../../www/py-django-tagging
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo118

EGG_NAME=	${DISTNAME:S/graphite-/graphite_/}

USE_LANGUAGES=	# none

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE GRAPHITE_DIR

REPLACE_SH+=		bin/build-index.sh

OWN_DIRS_PERMS+=	${GRAPHITE_LOG_DIR} ${GRAPHITE_USER} ${GRAPHITE_GROUP} 0755
OWN_DIRS_PERMS+=	${GRAPHITE_LOG_DIR}/webapp ${WWW_USER} ${GRAPHITE_GROUP} 0775

SUBST_CLASSES+=		dirs
SUBST_STAGE.dirs=	pre-configure
SUBST_MESSAGE.dirs=	Patching default dirs
SUBST_FILES.dirs=	bin/build-index.sh
SUBST_FILES.dirs+=	conf/graphite.wsgi.example
SUBST_FILES.dirs+=	examples/example-graphite-vhost.conf
SUBST_FILES.dirs+=	setup.py
SUBST_FILES.dirs+=	webapp/graphite/local_settings.py.example
SUBST_SED.dirs=		-e 's,/opt/graphite/conf,${PKG_SYSCONFDIR},g'
SUBST_SED.dirs+=	-e 's,/opt/graphite/storage/log,${GRAPHITE_LOG_DIR},g'
SUBST_SED.dirs+=	-e 's,/opt/graphite/storage,${GRAPHITE_DIR},g'
SUBST_SED.dirs+=	-e 's,/opt/graphite,${PREFIX}/graphite,g'
SUBST_VARS.dirs=	GRAPHITE_DIR GRAPHITE_EGDIR GRAPHITE_LOG_DIR PREFIX

MESSAGE_SUBST+=		GRAPHITE_DIR=${GRAPHITE_DIR}
MESSAGE_SUBST+=		GRAPHITE_LOG_DIR=${GRAPHITE_LOG_DIR}
MESSAGE_SUBST+=		GRAPHITE_USER=${GRAPHITE_USER}
MESSAGE_SUBST+=		WWW_USER=${WWW_USER}

PKG_SYSCONFSUBDIR=	graphite

GRAPHITE_CONF_FILES=	dashboard.conf graphite.wsgi graphTemplates.conf

.for file in ${GRAPHITE_CONF_FILES}
CONF_FILES+=		${GRAPHITE_EGDIR}/${file}.example	\
			${PKG_SYSCONFDIR}/${file}
.endfor

PYSETUPINSTALLARGS=		--prefix=${PREFIX}			\
				--install-lib=${PREFIX}/${PYSITELIB}
PYTHON_VERSIONS_ACCEPTED=	27 # py-django-tagging

INSTALLATION_DIRS+=	share/examples/graphite

pre-build:
	${MKDIR} ${WRKSRC}/graphite/webapp
	${CP} -LR ${WRKSRC}/webapp/content ${WRKSRC}/graphite/webapp
	${RM} -f ${WRKSRC}/bin/build-index.sh.orig

post-install:
	${LN} -s ${PKG_SYSCONFDIR}/local_settings.py ${DESTDIR}${PREFIX}/${PYSITELIB}/graphite/

.include "../../databases/py-carbon/Makefile.common"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
