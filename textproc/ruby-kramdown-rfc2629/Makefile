# $NetBSD: Makefile,v 1.35 2024/06/02 15:20:03 taca Exp $

DISTNAME=	kramdown-rfc2629-1.7.14
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cabo/kramdown-rfc2629
COMMENT=	IETF RFC 2629 back end for kramdown
LICENSE=	mit

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

DEPENDS+=	${RUBY_PKGPREFIX}-kramdown>=2.4.0<2.5:../../textproc/ruby-kramdown
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown-parser-gfm>=1.1<2:../../textproc/ruby-kramdown-parser-gfm
DEPENDS+=	${RUBY_PKGPREFIX}-certified>=1.0<2:../../security/ruby-certified
DEPENDS+=	${RUBY_PKGPREFIX}-unicode-name>=1.0<2:../../textproc/ruby-unicode-name
DEPENDS+=	${RUBY_PKGPREFIX}-unicode-blocks>=1.0<2:../../textproc/ruby-unicode-blocks
DEPENDS+=	${RUBY_PKGPREFIX}-unicode-scripts>=1.0<2:../../textproc/ruby-unicode-scripts
DEPENDS+=	${RUBY_PKGPREFIX}-net-http-persistent>=4.0<5:../../www/ruby-net-http-persistent
DEPENDS+=	${RUBY_PKGPREFIX}-differ>=0.1<1:../../textproc/ruby-differ

pre-configure:
	${CHMOD} +x ${WRKSRC}/bin/*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
