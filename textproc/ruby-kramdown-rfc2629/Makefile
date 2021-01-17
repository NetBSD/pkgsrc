# $NetBSD: Makefile,v 1.2 2021/01/17 17:26:15 riastradh Exp $

DISTNAME=	kramdown-rfc2629-1.3.24
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cabo/kramdown-rfc2629
COMMENT=	IETF RFC 2629 back end for kramdown
LICENSE=	mit

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC+=	certified:
OVERRIDE_GEMSPEC+=	kramdown>=2.0

DEPENDS+=	${RUBY_PKGPREFIX}-json>=2.0:../../textproc/ruby-json
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=2.0:../../textproc/ruby-kramdown

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
