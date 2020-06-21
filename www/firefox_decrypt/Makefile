# $NetBSD: Makefile,v 1.1 2020/06/21 20:25:45 wiz Exp $

DISTNAME=	firefox_decrypt-0.7.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=unode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/unode/firefox_decrypt/
COMMENT=	Extract passwords from Mozilla Firefox profiles
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON=			firefox_decrypt.py
INSTALLATION_DIRS=		bin

SUBST_CLASSES+=			nss
SUBST_FILES.nss+=		${REPLACE_PYTHON}
SUBST_STAGE.nss=		pre-configure
SUBST_VARS.nss+=		PREFIX

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/firefox_decrypt.py ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
