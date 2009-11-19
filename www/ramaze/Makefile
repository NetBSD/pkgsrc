# $NetBSD: Makefile,v 1.3 2009/11/19 14:11:03 fhajny Exp $

DISTNAME=	ramaze-2009.10
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ramaze.net/
COMMENT=	Ruby lightweight, modular, web application framework
LICENSE=	ruby-license

DEPENDS+=	rake>=0.7.3:../../devel/rake
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0.2.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-innate>=2009.10:../../www/ruby-innate

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
