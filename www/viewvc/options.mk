# $NetBSD: options.mk,v 1.1.1.1 2006/10/21 09:05:44 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.viewvc

PKG_SUPPORTED_OPTIONS=	cvsgraph viewvc-php

.include "../../mk/bsd.options.mk"
.include "../../lang/php/phpversion.mk"

###
### Use cvsgraph for printing pretty little pictures
###
.if !empty(PKG_OPTIONS:Mcvsgraph)
DEPENDS+=		cvsgraph-[0-9]*:../../devel/cvsgraph
CVSGRAPH_OPT=		1
.else
CVSGRAPH_OPT=		0
.endif

###
### Use php to colorize .php and .inc files
###
.if !empty(PKG_OPTIONS:Mviewvc-php)
.include "${PHPPKGSRCDIR}/buildlink3.mk"
PHP_OPT=		1
.else
PHP_OPT=		0
.endif
