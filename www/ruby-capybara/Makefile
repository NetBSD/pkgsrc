# $NetBSD: Makefile,v 1.10 2017/06/10 15:59:37 taca Exp $

DISTNAME=	capybara-2.14.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby www

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/jnicklas/capybara
COMMENT=	Integration testing tool for rack based web applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.3.3:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-rack14>=1.0.0:../../www/ruby-rack14
DEPENDS+=	${RUBY_PKGPREFIX}-rack-test>=0.5.4:../../www/ruby-rack-test
DEPENDS+=	${RUBY_PKGPREFIX}-xpath>=2.0:../../textproc/ruby-xpath
DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=0:../../net/ruby-addressable

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
