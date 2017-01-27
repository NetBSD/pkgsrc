# $NetBSD: options.mk,v 1.3 2017/01/27 12:11:13 roy Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.awstats

PKG_SUPPORTED_OPTIONS=  geoip whois

.include "../../mk/bsd.options.mk"

###
### Use the Geo IP Free module
###
.if !empty(PKG_OPTIONS:Mgeoip)
DEPENDS+=       p5-Geo-IPfree-[0-9]*:../../net/p5-Geo-IPfree
.endif

###
### Optional Whois support
###
.if !empty(PKG_OPTIONS:Mwhois)
DEPENDS+=       p5-Net-XWhois-[0-9]*:../../net/p5-Net-XWhois
.endif
