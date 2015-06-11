# $NetBSD: Makefile,v 1.4 2015/06/11 17:33:54 taca Exp $

DISTNAME=	capybara-2.4.4
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

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
