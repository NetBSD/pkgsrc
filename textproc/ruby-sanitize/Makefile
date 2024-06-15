# $NetBSD: Makefile,v 1.5 2024/06/15 16:32:25 taca Exp $

DISTNAME=	sanitize-6.1.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rgrove/sanitize/
COMMENT=	Allowlist-based HTML and CSS sanitizer
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-crass>=1.0.2<1.1:../../www/ruby-crass
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.12.0:../../textproc/ruby-nokogiri

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
