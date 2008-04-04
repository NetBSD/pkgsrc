# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:23:46 jlam Exp $

DISTNAME=	merb-core-0.9.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb core classes and framework

DEPENDS+=	erubis>=2.5.0:../../www/erubis
DEPENDS+=	rake>=0.8.1:../../devel/rake
DEPENDS+=	${RUBY_PKGPREFIX}-hpricot>=0.6:../../textproc/ruby-hpricot
DEPENDS+=	${RUBY_PKGPREFIX}-json-pure>=1.1.2:../../textproc/ruby-json-pure
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.15:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0.3:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.1.3:../../devel/ruby-rspec

# The merb-core gem lacks the ${WRKSRC}/tools directory.
GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
