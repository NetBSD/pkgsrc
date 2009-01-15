# $NetBSD: options.mk,v 1.2 2009/01/15 12:12:04 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.awstats

PKG_SUPPORTED_OPTIONS=	geoip

.include "../../mk/bsd.options.mk"

###
### Use the Geo IP Free module
###
.if !empty(PKG_OPTIONS:Mgeoip)
DEPENDS+=	p5-Geo-IPfree-[0-9]*:../../net/p5-Geo-IPfree
.endif
