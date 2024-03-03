# $NetBSD: Makefile,v 1.14 2024/03/03 08:44:47 taca Exp $

DISTNAME=	asciidoctor-2.0.21
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asciidoctor.org/
COMMENT=	Convert AsciiDoc to HTML and more
LICENSE=	mit

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable
RUBYGEM_MANPAGES=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
