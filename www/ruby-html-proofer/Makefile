# $NetBSD: Makefile,v 1.11 2023/01/21 13:59:53 taca Exp $

DISTNAME=	html-proofer-5.0.4
CATEGORIES=	www

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/gjtorikian/html-proofer
COMMENT=	Test your rendered HTML files to make sure they're accurate
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3<3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-async>=2.1<3:../../devel/ruby-async
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.13<2:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-rainbow>=3.0<4:../../misc/ruby-rainbow
DEPENDS+=	${RUBY_PKGPREFIX}-typhoeus>=1.3.1<2:../../www/ruby-typhoeus
DEPENDS+=	${RUBY_PKGPREFIX}-yell>=2.0<3:../../devel/ruby-yell
DEPENDS+=	${RUBY_PKGPREFIX}-zeitwerk>=2.5<3:../../devel/ruby-zeitwerk

USE_LANGUAGES=	# none

RUBY_VERSIONS_ACCEPTED=	31 32
RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
