# $NetBSD: Makefile,v 1.30.2.1 2023/01/08 15:57:24 bsiegert Exp $

DISTNAME=	kramdown-2.4.0
PKGREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kramdown.gettalong.org/
COMMENT=	Pure-Ruby Markdown-superset parser and converter
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable
RUBYGEM_MANPAGES=	yes

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
