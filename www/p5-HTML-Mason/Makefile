# $NetBSD: Makefile,v 1.14 2005/01/07 22:29:59 seb Exp $

DISTNAME=		HTML-Mason-1.28
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5hma
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.masonhq.com/
COMMENT=		Perl-based web site development and delivery system

DEPENDS+=               p5-Cache-Cache>=1.0:../../devel/p5-Cache-Cache
DEPENDS+=               p5-Params-Validate>=0.04:../../devel/p5-Params-Validate
DEPENDS+=		p5-Exception-Class>=1.14:../../devel/p5-Exception-Class
DEPENDS+=		p5-Class-Container>=0.10:../../devel/p5-Class-Container

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Mason/.packlist

# In case apache.mk is included below which will result in USE_PERL5
# being set to 'build' explicitly set it to 'run' here.
USE_PERL5=		run

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-HTML-Mason
PKG_SUPPORTED_OPTIONS=	modperl
PKG_DEFAULT_OPTIONS+=	modperl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmodperl)
.  include "../../mk/apache.mk"
.  if ${PKG_APACHE} == "apache13"
DEPENDS+=	p5-libapreq>=0.32:../../www/p5-libapreq
.include "../../www/ap-perl/buildlink3.mk"
.  elif ${PKG_APACHE} == "apache2"
DEPENDS+=	p5-libapreq2-[0-9]*:../../www/p5-libapreq2
.include "../../www/ap2-perl/buildlink3.mk"
.  endif
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
