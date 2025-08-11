# $NetBSD: Makefile,v 1.2 2025/08/11 16:39:46 taca Exp $

DISTNAME=	llhttp-ffi-0.5.1
CATEGORIES=	www

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/llhttp-ffi/
COMMENT=	Ruby FFI bindings for llhttp
LICENSE=	mpl-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-ffi-compiler>=1.0:../../devel/ruby-ffi-compiler

USE_LANGUAGES=	c
GEM_CLEANBUILD=	# empty

OVERRIDE_GEMSPEC+=	:files ext/aarch64-darwin/libllhttp-ext.bundle= \
				ext/aarch64-darwin/llhttp/api.o= \
				ext/aarch64-darwin/llhttp/http.o= \
				ext/aarch64-darwin/llhttp/llhttp.o= \
				ext/aarch64-darwin/llhttp/llhttp_ext.o=

post-extract:
	${RM} -rf ${WRKSRC}/ext/aarch64-darwin

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
