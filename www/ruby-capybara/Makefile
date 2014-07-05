# $NetBSD: Makefile,v 1.2 2014/07/05 21:00:23 joerg Exp $

DISTNAME=	capybara-2.4.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby www

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/jnicklas/capybara
COMMENT=	Integration testing tool for rack based web applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.3.3:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.0.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-rack-test>=0.5.4:../../www/ruby-rack-test
DEPENDS+=	${RUBY_PKGPREFIX}-xpath>=2.0:../../textproc/ruby-xpath

USE_LANGUAGES=	# none

RUBY_VERSION_SUPPORTED=	200 193 21

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
