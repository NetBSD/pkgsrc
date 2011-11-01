# $NetBSD: options.mk,v 1.2 2011/11/01 21:08:55 scottr Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.viewvc

PKG_SUPPORTED_OPTIONS=	cvsgraph

.include "../../mk/bsd.options.mk"

###
### Use cvsgraph for printing pretty little pictures
###
.if !empty(PKG_OPTIONS:Mcvsgraph)
DEPENDS+=		cvsgraph-[0-9]*:../../devel/cvsgraph
CVSGRAPH_OPT=		1
.else
CVSGRAPH_OPT=		0
.endif
