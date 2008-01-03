# $NetBSD: options.mk,v 1.1 2008/01/03 12:37:06 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.awstats

PKG_SUPPORTED_OPTIONS=	awstats-geoipfree

.include "../../mk/bsd.options.mk"

###
### Use the Geo IP Free module
###
.if !empty(PKG_OPTIONS:Mawstats-geoipfree)
DEPENDS+=	p5-Geo-IPfree-[0-9]*:../../net/p5-Geo-IPfree
.endif
