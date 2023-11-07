# $NetBSD: Makefile,v 1.5 2023/11/07 22:38:08 wiz Exp $

DISTNAME=	mailman-web-0.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mailman-web/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.list.org/
COMMENT=	Mailman 3 Web interface
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django3
DEPENDS+=	${PYPKGPREFIX}-hyperkitty-[0-9]*:../../www/py-hyperkitty
DEPENDS+=	${PYPKGPREFIX}-postorius-[0-9]*:../../www/py-postorius
DEPENDS+=	${PYPKGPREFIX}-Whoosh-[0-9]*:../../textproc/py-Whoosh

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

BUILD_DEFS+=		VARBASE

PKG_SYSCONFSUBDIR=	mailman3

SUBST_CLASSES+=		fhs
SUBST_STAGE.fhs=	pre-configure
SUBST_FILES.fhs=	mailman_web/manage.py
SUBST_FILES.fhs+=	mailman_web/settings/base.py
SUBST_FILES.fhs+=	mailman_web/settings/mailman.py
SUBST_FILES.fhs+=	crontab.sample
SUBST_MESSAGE.fhs=	Fixing default paths
SUBST_VARS.fhs=		PKG_SYSCONFDIR PREFIX VARBASE

MAILMAN_USER?=		mailman
MAILMAN_GROUP?=		mailman

PKG_GROUPS_VARS+=	MAILMAN_GROUP
PKG_USERS_VARS+=	MAILMAN_USER

PKG_GROUPS=		${MAILMAN_GROUP}
PKG_USERS=		${MAILMAN_USER}:${MAILMAN_GROUP}

PKG_GECOS.${MAILMAN_USER}=	Mailman user
PKG_SHELL.${MAILMAN_USER}=	${SH}

FILES_SUBST+=		MAILMAN_USER=${MAILMAN_USER}
FILES_SUBST+=		MAILMAN_GROUP=${MAILMAN_GROUP}
FILES_SUBST+=		PYTHONBIN=${PYTHONBIN}

RCD_SCRIPTS=		mailman-web

OWN_DIRS_PERMS+=	${VARBASE}/lib/mailman-web ${MAILMAN_USER} ${MAILMAN_GROUP} 775
OWN_DIRS_PERMS+=	${VARBASE}/lib/mailman-web/data ${MAILMAN_USER} ${MAILMAN_GROUP} 770
OWN_DIRS_PERMS+=	${VARBASE}/log/mailman-web ${MAILMAN_USER} ${MAILMAN_GROUP} 770

EGDIR=			share/examples/mailman-web
CONF_FILES_PERMS=	${EGDIR}/settings.py ${PKG_SYSCONFDIR}/settings.py \
			${MAILMAN_USER} ${MAILMAN_GROUP} 0640

INSTALLATION_DIRS+=	${EGDIR}

post-patch:
	${CP} ${FILESDIR}/crontab.sample ${WRKSRC}/crontab.sample

post-install:
	${INSTALL_DATA} ${FILESDIR}/settings.py ${DESTDIR}${PREFIX}/${EGDIR}/settings.py
	${INSTALL_DATA} ${WRKSRC}/crontab.sample ${DESTDIR}${PREFIX}/${EGDIR}/crontab.sample

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
