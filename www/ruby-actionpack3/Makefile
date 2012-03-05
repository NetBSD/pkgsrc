# $NetBSD: Makefile,v 1.10.2.1 2012/03/05 23:28:40 tron Exp $

DISTNAME=	actionpack-${RUBY_RAILS3_VERSION}
PKGREVISION=	3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Toolkit for building modeling frameworks (part of Rails)
LICENSE=	mit

# Comment out dependency in gemspec but already depends indirectly one.
#DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.1.2:../../textproc/ruby-builder
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.5<1:../../devel/ruby-i18n_05
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.2.1<1.3:../../www/ruby-rack12
DEPENDS+=	${RUBY_PKGPREFIX}-rack-test>=0.5.7<0.6:../../www/ruby-rack-test05
DEPENDS+=	${RUBY_PKGPREFIX}-rack-mount>=0.6.14<0.7:../../www/ruby-rack-mount06
DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo>=0.3.23<0.4:../../time/ruby-tzinfo
DEPENDS+=	${RUBY_PKGPREFIX}-erubis>=2.6.6<2.7:../../www/ruby-erubis26

RUBY_RAILS_SUPPORTED=	3

OVERRIDE_GEMSPEC+=	builder>=2.1.2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
