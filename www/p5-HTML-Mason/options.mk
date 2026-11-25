# $NetBSD: options.mk,v 1.7 2026/11/25 17:16:36 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-HTML-Mason
PKG_SUPPORTED_OPTIONS=	fastcgi modperl
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

###
### mod_perl usage for Apache webservers
###
.if !empty(PKG_OPTIONS:Mmodperl)
.include "../../www/apache24/buildlink3.mk"
DEPENDS+=	p5-ap24-libapreq2-[0-9]*:../../www/p5-libapreq2
.include "../../www/ap2-perl/buildlink3.mk"
.endif

###
### FastCGI Support e.g. for lighttpd
###
.if !empty(PKG_OPTIONS:Mfastcgi)
DEPENDS+=	p5-FCGI-[0-9]*:../../www/p5-FCGI
.endif
