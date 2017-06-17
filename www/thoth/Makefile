# $NetBSD: Makefile,v 1.12 2017/06/17 05:07:11 taca Exp $

DISTNAME=	thoth-0.2.1
PKGREVISION=	5
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rgrove/thoth
COMMENT=	Minimalistic blog engine
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-ramaze>=2008.06:../../www/ramaze
DEPENDS+=	${RUBY_PKGPREFIX}-erubis>=2.7.0<3:../../www/ruby-erubis
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.1.2:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-configuration>=0.0.5:../../misc/ruby-configuration
DEPENDS+=	${RUBY_PKGPREFIX}-cssmin>=1.0.2<1.1:../../www/ruby-cssmin
DEPENDS+=	${RUBY_PKGPREFIX}-hpricot>=0.6<1:../../textproc/ruby-hpricot
DEPENDS+=	${RUBY_PKGPREFIX}-jsmin>=1.0.0<1.1:../../www/ruby-jsmin
DEPENDS+=	${RUBY_PKGPREFIX}-redcloth>=4.0.3:../../textproc/ruby-redcloth
DEPENDS+=	${RUBY_PKGPREFIX}-sequel>=2.5.0:../../databases/ruby-sequel
DEPENDS+=	${RUBY_PKGPREFIX}-thin>=0.8.2:../../www/thin

RUBYGEM_OPTIONS+=	--format-executable

OVERRIDE_GEMSPEC+= \
	builder>=2.1.2 configuration>=0.0.5 json-pure>=1.1.3 redcloth>=4.0.3 \
	ramaze>=2008.06 sequel>=2.5.0 thin>=0.8.2 erubis>=2.7.0 \
	json_pure:json>=1.1.3

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
