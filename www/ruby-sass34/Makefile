# $NetBSD: Makefile,v 1.2 2019/02/24 16:22:26 taca Exp $

DISTNAME=	sass-3.4.25
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/sass/sass34/}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sass-lang.com/
COMMENT=	Powerful, but elegant CSS compiler that makes CSS fun again
LICENSE=	mit

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable
SASS_COMMANDS=		sass sass-convert scss

.for f in ${SASS_COMMANDS}
OVERRIDE_GEMSPEC+=	:executables ${f}=${f}34
OVERRIDE_GEMSPEC+=	:files bin/${f}=bin/${f}34
.endfor

pre-configure:
.for f in ${SASS_COMMANDS}
	mv ${WRKSRC}/bin/${f} ${WRKSRC}/bin/${f}34
.endfor

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
