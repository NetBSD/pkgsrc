# $NetBSD: options.mk,v 1.5 2017/03/11 23:21:11 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-HTML-Mason
PKG_SUPPORTED_OPTIONS=	fastcgi modperl
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

###
### mod_perl usage for Apache webservers
###
.if !empty(PKG_OPTIONS:Mmodperl)
.  include "../../mk/apache.mk"
DEPENDS+=	p5-${APACHE_PKG_PREFIX}-libapreq2-[0-9]*:../../www/p5-libapreq2
.include "../../www/ap2-perl/buildlink3.mk"
.endif

###
### FastCGI Support e.g. for lighttpd
###
.if !empty(PKG_OPTIONS:Mfastcgi)
DEPENDS+=	p5-FCGI-[0-9]*:../../www/p5-FCGI
.endif
