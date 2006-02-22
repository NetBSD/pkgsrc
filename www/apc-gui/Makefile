# $NetBSD: Makefile,v 1.17 2006/02/22 07:10:23 wiz Exp $

DISTNAME=	apc_gui-1.0.3
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://apc.neuropeans.com/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://apc.neuropeans.com/
COMMENT=	Web interface for managing APC (php-apc)

PHP_VERSION_REQD=	4

DEPENDS+=	php-apc>=1.1.0.1:../../www/php4-apc
DEPENDS+=	php-gd-4.[0-9]*:../../graphics/php-gd

NO_BUILD=	YES

PKG_SYSCONFSUBDIR?=	httpd
APC_GUI_DIR=		${PREFIX}/share/apc-gui
EGDIR=			${PREFIX}/share/examples/apc-gui
PLIST_SUBST+=		PKGBASE=${PKGBASE:Q}
MESSAGE_SUBST+=		APC_GUI_DIR=${APC_GUI_DIR}

CONF_FILES=	${EGDIR}/apc_gui.conf ${PKG_SYSCONFDIR}/apc_gui.conf
CONF_FILES+=	/dev/null ${APC_GUI_DIR}/apc_config_local.php

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/apc_gui.conf.dist
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@APC_GUI_DIR@,${APC_GUI_DIR},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	${CP} ${FILESDIR}/apc_gui.conf.dist ${WRKDIR}

do-install:
	${INSTALL_DATA_DIR} ${APC_GUI_DIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/apc_gui.conf.dist ${EGDIR}/apc_gui.conf
	${CP} -R ${WRKSRC}/* ${APC_GUI_DIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${APC_GUI_DIR}

.include "../../mk/bsd.pkg.mk"
