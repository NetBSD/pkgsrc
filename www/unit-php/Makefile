# $NetBSD: Makefile,v 1.2 2021/02/14 13:43:40 otis Exp $

PKGNAME=	unit-${LANG}${PHP_VERSION:R:S|.||g}-${UNIT_VERSION}
COMMENT=	PHP module for NGINX Unit

LANG=		php
MODNAME=	${LANG}${PHP_VERSION}

MAINTAINER=	osa@FreeBSD.org

PHP_VERSIONS_ACCEPTED?=	56 72 73 74

.include "../../lang/php/phpversion.mk"

#.if empty(PKG_BUILD_OPTIONS.${PHP_PKG_PREFIX}:Mphp-embed)
#BROKEN=		"Requires the php-embed option enabled in PHP."
#.endif

post-configure:
	${RUN} cd ${WRKSRC} && ${SETENV} ${_CONFIGURE_SCRIPT_ENV}	\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} 			\
			${CONFIGURE_SCRIPT} ${LANG}			\
				--lib-path=${PREFIX}/lib		\
				--module=${MODNAME}

.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../www/unit/ext.mk"
.include "../../www/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
