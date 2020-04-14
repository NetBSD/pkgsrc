# $NetBSD: Makefile,v 1.1 2020/04/14 16:04:41 ryoon Exp $

DISTNAME=	nokogumbo-2.0.2
CATEGORIES=	textproc
MASTER_SITES=	https://rubygems.org/downloads/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/nokogumbo/
COMMENT=	Gumbo HTML5 parser to parse with Nokogiri
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.10:../../textproc/ruby-nokogiri

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
