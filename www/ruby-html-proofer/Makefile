# $NetBSD: Makefile,v 1.5 2022/08/31 14:47:35 taca Exp $

DISTNAME=	html-proofer-4.4.0
CATEGORIES=	www

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/html-proofer/
COMMENT=	Test your rendered HTML files to make sure they're accurate
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3<3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-mercenary>=0.3<1:../../devel/ruby-mercenary
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.13<2:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-parallel>=1.10<2:../../misc/ruby-parallel
DEPENDS+=	${RUBY_PKGPREFIX}-rainbow>=3.0<4:../../misc/ruby-rainbow
DEPENDS+=	${RUBY_PKGPREFIX}-typhoeus>=1.3.1<2:../../www/ruby-typhoeus
DEPENDS+=	${RUBY_PKGPREFIX}-yell>=2.0<3:../../devel/ruby-yell
DEPENDS+=	${RUBY_PKGPREFIX}-zeitwerk>=2.5<3:../../devel/ruby-zeitwerk

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
