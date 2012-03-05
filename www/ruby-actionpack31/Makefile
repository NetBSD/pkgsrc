# $NetBSD: Makefile,v 1.1.1.1.2.1 2012/03/05 23:28:40 tron Exp $

DISTNAME=	actionpack-${RUBY_RAILS_VERSION}
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails)
LICENSE=	mit

# Comment out dependency in gemspec but already depends indirectly one.
#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
#DEPENDS+=	${RUBY_PKGPREFIX}-builder>=3.0.0<3.1:../../textproc/ruby-builder
#DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.6<1:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.3.5<1.4:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-rack-cache>=1.1<2:../../www/ruby-rack-cache
DEPENDS+=	${RUBY_PKGPREFIX}-rack-test>=0.6.1<0.7:../../www/ruby-rack-test
DEPENDS+=	${RUBY_PKGPREFIX}-rack-mount>=0.8.2<0.9:../../www/ruby-rack-mount
DEPENDS+=	${RUBY_PKGPREFIX}-sprockets>=2.0.3<2.1:../../misc/ruby-sprockets
DEPENDS+=	${RUBY_PKGPREFIX}-erubis>=2.7.0<2.8:../../www/ruby-erubis

RUBY_RAILS_SUPPORTED=	31

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
