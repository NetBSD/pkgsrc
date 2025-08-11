# $NetBSD: Makefile,v 1.1 2025/08/11 11:51:08 ryoon Exp $

DISTNAME=	llhttp-ffi-0.5.1
CATEGORIES=	www

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/llhttp-ffi/
COMMENT=	Ruby FFI bindings for llhttp
LICENSE=	mpl-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-ffi-compiler>=1.0:../../devel/ruby-ffi-compiler

USE_LANGUAGES=	c
GEM_CLEANBUILD=	# empty

post-extract:
	${RM} -rf ${WRKSRC}/ext/aarch64-darwin

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
