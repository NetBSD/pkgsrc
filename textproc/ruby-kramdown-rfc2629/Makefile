# $NetBSD: Makefile,v 1.17 2023/02/23 15:32:48 taca Exp $

DISTNAME=	kramdown-rfc2629-1.6.24
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cabo/kramdown-rfc2629
COMMENT=	IETF RFC 2629 back end for kramdown
LICENSE=	mit

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

OVERRIDE_GEMSPEC+=	kramdown>=2.4.0

DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=2.3.0:../../textproc/ruby-kramdown
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown-parser-gfm>=1.1<2:../../textproc/ruby-kramdown-parser-gfm
DEPENDS+=	${RUBY_PKGPREFIX}-certified>=1.0<2:../../security/ruby-certified

pre-configure:
	${CHMOD} +x ${WRKSRC}/bin/*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
