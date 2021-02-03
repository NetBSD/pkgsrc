# $NetBSD: Makefile,v 1.3 2021/02/03 15:29:47 taca Exp $

DISTNAME=	kramdown-rfc2629-1.3.25
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cabo/kramdown-rfc2629
COMMENT=	IETF RFC 2629 back end for kramdown
LICENSE=	mit

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	certified:
OVERRIDE_GEMSPEC+=	kramdown>=2.0

#DEPENDS+=	${RUBY_PKGPREFIX}-json>=2.0:../../textproc/ruby-json
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=2.0:../../textproc/ruby-kramdown

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
