# $NetBSD: Makefile,v 1.12 2005/09/22 14:53:41 wiz Exp $

DISTNAME=	apc_gui-1.0.3
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://apc.neuropeans.com/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://apc.neuropeans.com/
COMMENT=	Web interface for managing APC (php-apc)

PHP_VERSION_REQD=	4

DEPENDS+=	php-apc>=1.1.0.1:../../www/php4-apc
DEPENDS+=	php-gd-4.[0-9]*:../../graphics/php-gd

NO_BUILD=	YES
USE_PKGINSTALL=	YES

PKG_SYSCONFSUBDIR?=	httpd
APC_GUI_DIR=		${PREFIX}/share/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
PLIST_SUBST+=		PKGBASE=${PKGBASE}
MESSAGE_SUBST+=		APC_GUI_DIR=${APC_GUI_DIR}

CONF_FILES=	${EGDIR}/apc_gui.conf ${PKG_SYSCONFDIR}/apc_gui.conf
CONF_FILES+=	/dev/null ${APC_GUI_DIR}/apc_config_local.php
OWN_DIRS=	${APC_GUI_DIR}

pre-install:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/apc_gui.conf.dist		\
		> ${WRKDIR}/apc_gui.conf.dist

do-install:
	${INSTALL_DATA_DIR} ${APC_GUI_DIR} ${EGDIR}
	cd ${WRKDIR}; ${INSTALL_DATA} apc_gui.conf.dist			\
		${EGDIR}/apc_gui.conf
	${CP} -R ${WRKSRC}/* ${APC_GUI_DIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${APC_GUI_DIR}

.include "../../mk/bsd.pkg.mk"
