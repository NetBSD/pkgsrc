# $NetBSD: Makefile,v 1.16 2025/02/08 04:16:34 taca Exp $

PKGNAME=	unit-${LANG}${PHP_VER}-${UNIT_VERSION}
PKGREVISION=	1
COMMENT=	PHP module for NGINX Unit

LANG=		php
MODNAME=	${LANG}${PHP_VERSION}

MAINTAINER=	osa@NetBSD.org

CONFIGURE_ENV+=		PHP_VER=${PHP_VER}

post-configure:
	${RUN} cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV}		\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} 			\
			${CONFIGURE_SCRIPT} ${LANG}			\
				--config=php-config${PHP_VER}		\
				--lib-path=${PREFIX}/lib		\
				--module=${MODNAME}

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"

.if empty(PKG_BUILD_OPTIONS.${PHP_PKG_PREFIX}:Mphp-embed)
PKG_FAIL_REASON=	"Requires the php-embed option enabled in PHP."
.endif
.include "../../www/unit/ext.mk"
.include "../../www/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
