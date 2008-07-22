# $NetBSD: options.mk,v 1.1 2008/07/22 21:41:56 rhaen Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-HTML-Mason
PKG_SUPPORTED_OPTIONS=	cache fcgi modperl
PKG_SUGGESTED_OPTIONS=	cache

.include "../../mk/bsd.options.mk"

###
### mod_perl usage for Apache webservers
###
.if !empty(PKG_OPTIONS:Mmodperl)
.  include "../../mk/apache.mk"
.  if ${PKG_APACHE} == "apache13"
DEPENDS+=	p5-libapreq>=0.32:../../www/p5-libapreq
.    include "../../www/ap-perl/buildlink3.mk"
.  elif ${PKG_APACHE} == "apache2" || ${PKG_APACHE} == "apache22"
DEPENDS+=	p5-libapreq2-[0-9]*:../../www/p5-libapreq2
.    include "../../www/ap2-perl/buildlink3.mk"
.  endif
.endif

###
### FastCGI Support e.g. for lighttpd
###
.if !empty(PKG_OPTIONS:Mfcgi)
DEPENDS+=	p5-FCGI-[0-9]*:../../www/p5-FCGI
.endif

###
### The Perl module Cache-Cache for optional caching
###
.if !empty(PKG_OPTIONS:Mcache)
DEPENDS+=	p5-Cache-Cache>=1.0:../../devel/p5-Cache-Cache
.endif
