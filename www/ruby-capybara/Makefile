# $NetBSD: Makefile,v 1.26 2021/01/26 15:02:11 taca Exp $

DISTNAME=	capybara-3.35.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jnicklas/capybara
COMMENT=	Integration testing tool for rack based web applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=0:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-mini_mime>=0.1.3:../../mail/ruby-mini_mime
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.8:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.6.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-rack-test>=0.6.3:../../www/ruby-rack-test
DEPENDS+=	${RUBY_PKGPREFIX}-regexp_parser>=1.5:../../devel/ruby-regexp_parser
DEPENDS+=	${RUBY_PKGPREFIX}-xpath>=3.2<4:../../textproc/ruby-xpath

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
