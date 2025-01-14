# $NetBSD: Makefile,v 1.8 2025/01/14 09:46:21 wiz Exp $

DISTNAME=	matrix_sydent-2.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/matrix_//}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/matrix-sydent/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/matrix-org/sydent
COMMENT=	Matrix Identity Servers
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.0.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=16.0.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.1.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-matrix-common>=1.1.0:../../chat/py-matrix-common
DEPENDS+=	${PYPKGPREFIX}-nacl>=1.2.1:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-netaddr>=0.7.0:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-phonenumbers>=8.12.32:../../textproc/py-phonenumbers
DEPENDS+=	${PYPKGPREFIX}-prometheus_client>=0.4.0:../../net/py-prometheus_client
DEPENDS+=	${PYPKGPREFIX}-service_identity>=1.0.0:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-signedjson>=1.1.1:../../security/py-signedjson
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.1.0:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-twisted>=18.4.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-unpaddedbase64>=1.1.0:../../devel/py-unpaddedbase64
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=4.6.0:../../devel/py-zope.interface

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

# Avoid the pyNN- prefix in config, doc, and so on.
HUMAN_PKGNAME=	sydent

.include "../../mk/bsd.prefs.mk"

SYDENT_USER?=		sydent
SYDENT_GROUP?=		${SYDENT_USER}
SYDENT_DATA?=		${VARBASE}/db/${HUMAN_PKGNAME}
BUILD_DEFS+=		SYDENT_USER SYDENT_GROUP SYDENT_DATA VARBASE

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
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
