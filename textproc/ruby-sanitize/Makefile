# $NetBSD: Makefile,v 1.2.4.1 2023/08/13 09:03:45 bsiegert Exp $

DISTNAME=	sanitize-6.0.2
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
