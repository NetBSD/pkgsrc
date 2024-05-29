# $NetBSD: Makefile,v 1.8 2024/05/29 16:34:40 adam Exp $

DISTNAME=	nokogumbo-2.0.5
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	https://rubygems.org/downloads/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/nokogumbo/
COMMENT=	Gumbo HTML5 parser to parse with Nokogiri
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.10:../../textproc/ruby-nokogiri

.include "../../lang/ruby/gem.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
