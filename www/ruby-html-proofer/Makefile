# $NetBSD: Makefile,v 1.1 2020/04/14 16:10:50 ryoon Exp $

DISTNAME=	html-proofer-3.15.2
CATEGORIES=	www
MASTER_SITES=	http://rubygems.org/downloads/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/html-proofer/
COMMENT=	Test your rendered HTML files to make sure they're accurate
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-mercenary>=0.3:../../devel/ruby-mercenary
DEPENDS+=	${RUBY_PKGPREFIX}-nokogumbo>=2.0.2:../../textproc/ruby-nokogumbo
DEPENDS+=	${RUBY_PKGPREFIX}-parallel>=1.3:../../misc/ruby-parallel
DEPENDS+=	${RUBY_PKGPREFIX}-rainbow>=3.0:../../misc/ruby-rainbow
DEPENDS+=	${RUBY_PKGPREFIX}-typhoeus>=1.3.1:../../www/ruby-typhoeus
DEPENDS+=	${RUBY_PKGPREFIX}-yell>=1.3.1:../../devel/ruby-yell

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
