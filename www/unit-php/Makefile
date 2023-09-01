# $NetBSD: Makefile,v 1.12 2023/09/01 17:28:29 osa Exp $

PKGNAME=	unit-${LANG}${PKG_PHP_VERSION}-${UNIT_VERSION}
COMMENT=	PHP module for NGINX Unit

LANG=		php
MODNAME=	${LANG}${PHP_VERSION}

MAINTAINER=	osa@NetBSD.org

PHP_VERSIONS_ACCEPTED?=	56 74 80 81 82

.include "../../lang/php/phpversion.mk"

post-configure:
	${RUN} cd ${WRKSRC} && ${SETENV} ${_CONFIGURE_SCRIPT_ENV}	\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} 			\
			${CONFIGURE_SCRIPT} ${LANG}			\
				--lib-path=${PREFIX}/lib		\
				--module=${MODNAME}

.include "${PHPPKGSRCDIR}/buildlink3.mk"
.if empty(PKG_BUILD_OPTIONS.php:Mphp-embed)
PKG_FAIL_REASON=	"Requires the php-embed option enabled in PHP."
.endif
.include "../../www/unit/ext.mk"
.include "../../www/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
