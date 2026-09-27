# $NetBSD: Makefile,v 1.1 2026/09/27 13:44:05 taca Exp $

DISTNAME=	rubyXL-3.4.38
CATEGORIES=	textproc ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gilt/rubyXL
COMMENT=	Parsing, creation, and manipulation of Microsoft Excel
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.10.8:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-zip>=3.2.2:../../archivers/ruby-zip

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
