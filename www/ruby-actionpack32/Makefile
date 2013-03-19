# $NetBSD: Makefile,v 1.6 2013/03/19 16:13:26 taca Exp $

DISTNAME=	actionpack-${RUBY_RAILS_VERSION}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails 3.2)
LICENSE=	mit

# Comment out dependency in gemspec but already depends indirectly one.
#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
#DEPENDS+=	${RUBY_PKGPREFIX}-builder>=3.0.0<3.1:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-rack14>=1.4.5<1.5:../../www/ruby-rack14
DEPENDS+=	${RUBY_PKGPREFIX}-rack-cache>=1.2<2:../../www/ruby-rack-cache
DEPENDS+=	${RUBY_PKGPREFIX}-rack-test>=0.6.1<0.7:../../www/ruby-rack-test
DEPENDS+=	${RUBY_PKGPREFIX}-journey>=1.0.4<1.1:../../www/ruby-journey
DEPENDS+=	${RUBY_PKGPREFIX}-sprockets>=2.2.1<2.3:../../misc/ruby-sprockets22
DEPENDS+=	${RUBY_PKGPREFIX}-erubis>=2.7.0<2.8:../../www/ruby-erubis

RUBY_RAILS_SUPPORTED=	32
RUBY_RAILS_STRICT_DEP=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
