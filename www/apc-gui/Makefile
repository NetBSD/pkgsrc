# $NetBSD: Makefile,v 1.3 2001/11/25 18:59:49 jlam Exp $

DISTNAME=	apc_gui-1.0.3
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	www
MASTER_SITES=	http://apc.neuropeans.com/download/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://apc.neuropeans.com/
COMMENT=	web interface for managing APC (php-apc)

DEPENDS+=	php-apc>=1.1.0.1:../../www/php4-apc
DEPENDS+=	php-gd>=4.0.1:../../graphics/php4-gd

NO_BUILD=	YES

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
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_DATA_DIR} ${APC_GUI_DIR} ${EGDIR}
	cd ${WRKDIR}; ${INSTALL_DATA} apc_gui.conf.dist			\
		${EGDIR}/apc_gui.conf
	${CP} -R ${WRKSRC}/* ${APC_GUI_DIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${APC_GUI_DIR}
	${CHMOD} -R a-w ${APC_GUI_DIR}

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
