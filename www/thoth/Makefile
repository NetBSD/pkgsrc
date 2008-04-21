# $NetBSD: Makefile,v 1.4 2008/04/21 16:33:19 jlam Exp $

DISTNAME=	thoth-0.1.4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thothblog.org/
COMMENT=	Minimalistic blog engine

DEPENDS+=	erubis>=2.5.0:../../www/erubis
DEPENDS+=	ramaze>=0.3.9.1:../../www/ramaze
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.1.2:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-configuration>=0.0.5:../../misc/ruby-configuration
DEPENDS+=	${RUBY_PKGPREFIX}-cssmin>=1.0.0:../../www/ruby-cssmin
DEPENDS+=	${RUBY_PKGPREFIX}-hpricot>=0.6:../../textproc/ruby-hpricot
DEPENDS+=	${RUBY_PKGPREFIX}-jsmin>=1.0.0:../../www/ruby-jsmin
DEPENDS+=	${RUBY_PKGPREFIX}-json-pure>=1.1.2:../../textproc/ruby-json-pure
DEPENDS+=	${RUBY_PKGPREFIX}-redcloth>=3.0.4:../../textproc/ruby-redcloth
DEPENDS+=	${RUBY_PKGPREFIX}-sequel-core>=1.4.0:../../databases/ruby-sequel-core
DEPENDS+=	${RUBY_PKGPREFIX}-sequel>=1.4.0:../../databases/ruby-sequel
DEPENDS+=	thin>=0.7.1:../../www/thin

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
