# $NetBSD: Makefile,v 1.35 2023/06/11 14:33:41 taca Exp $

DISTNAME=	capybara-3.39.2
CATEGORIES=	www devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jnicklas/capybara
COMMENT=	Integration testing tool for rack based web applications
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=0:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-mini_mime>=0.1.3:../../mail/ruby-mini_mime
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.8<2:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.6.0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-rack-test>=0.6.3:../../www/ruby-rack-test
DEPENDS+=	${RUBY_PKGPREFIX}-regexp_parser>=1.5:../../devel/ruby-regexp_parser
DEPENDS+=	${RUBY_PKGPREFIX}-xpath>=3.2<4:../../textproc/ruby-xpath

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
