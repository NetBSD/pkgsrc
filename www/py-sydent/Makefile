# $NetBSD: Makefile,v 1.6 2023/10/23 06:37:57 wiz Exp $

DISTNAME=	py-sydent-2.5.6
EGG_NAME=	SynapseIdentityServer-0.1
PKGREVISION=	4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py-//}
CATEGORIES=	www
GITHUB_PROJECT=	sydent
MASTER_SITES=	${MASTER_SITE_GITHUB:=matrix-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/matrix-org/sydent
COMMENT=	Matrix Identity Servers
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-daemonize>=2.4.7:../../devel/py-daemonize
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-libnacl-[0-9]*:../../security/py-libnacl
DEPENDS+=	${PYPKGPREFIX}-matrix-common>=0:../../chat/py-matrix-common
DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-nacl-[0-9]*:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-netaddr-[0-9]*:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized
DEPENDS+=	${PYPKGPREFIX}-phonenumbers-[0-9]*:../../textproc/py-phonenumbers
DEPENDS+=	${PYPKGPREFIX}-prometheus_client-[0-9]*:../../net/py-prometheus_client
DEPENDS+=	${PYPKGPREFIX}-service_identity-[0-9]*:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-setuptools_trial-[0-9]*:../../devel/py-setuptools_trial
DEPENDS+=	${PYPKGPREFIX}-signedjson-[0-9]*:../../security/py-signedjson
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers-[0-9]*:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-unpaddedbase64-[0-9]*:../../devel/py-unpaddedbase64
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

PYTHON_VERSIONS_INCOMPATIBLE=	27

#USE_LANGUAGES=	# none

# Avoid the pyNN- prefix in config, doc, and so on.
HUMAN_PKGNAME=	sydent

.include "../../mk/bsd.prefs.mk"

SYDENT_USER?=			sydent
SYDENT_GROUP?=			${SYDENT_USER}
SYDENT_DATA?=			${VARBASE}/db/${HUMAN_PKGNAME}
BUILD_DEFS+=			SYDENT_USER SYDENT_GROUP SYDENT_DATA VARBASE

OWN_DIRS_PERMS+=	${SYDENT_DATA} ${SYDENT_USER} ${SYDENT_GROUP} 0770
OWN_DIRS_PERMS+=	${SYDENT_DATA}/res ${SYDENT_USER} ${SYDENT_GROUP} 0770

PKG_USERS_VARS=			SYDENT_USER
PKG_GROUPS_VARS=		SYDENT_GROUP
PKG_GROUPS=			${SYDENT_GROUP}
PKG_USERS=			${SYDENT_USER}:${SYDENT_GROUP}
PKG_GECOS.${SYDENT_USER}=	Sydent daemon user
PKG_HOME.${SYDENT_USER}=	${SYDENT_DATA}
PKG_SHELL.${SYDENT_USER}=	${NOLOGIN}

RCD_SCRIPTS=	sydent

FILES_SUBST+=	SYDENT_DATA=${SYDENT_DATA:Q}
FILES_SUBST+=	SYDENT_USER=${SYDENT_USER:Q}
FILES_SUBST+=	SYDENT_GROUP=${SYDENT_GROUP:Q}
FILES_SUBST+=	PYTHONBIN=${PYTHONBIN:Q}

EGDIR=			${PREFIX}/share/examples/${HUMAN_PKGNAME}
CONF_FILES_PERMS+=	${EGDIR}/sydent.conf ${PKG_SYSCONFDIR}/sydent.conf \
			${SYDENT_USER} ${SYDENT_GROUP} 0755
INSTALLATION_DIRS+=	${EGDIR}

post-configure:
	${SED} -e "s|@SYDENT_DATA@|${SYDENT_DATA}|" \
	    ${FILESDIR}/sydent.conf > ${WRKSRC}/sydent.conf

post-install:
	${INSTALL_DATA}	${WRKSRC}/sydent.conf ${DESTDIR}${EGDIR}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
