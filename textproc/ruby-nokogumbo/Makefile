# $NetBSD: Makefile,v 1.7 2023/11/08 13:21:09 wiz Exp $

DISTNAME=	nokogumbo-2.0.5
PKGREVISION=	2
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
