# $NetBSD: Makefile,v 1.11 2022/12/29 16:23:52 taca Exp $

DISTNAME=	asciidoctor-2.0.18
PKGREVISION=	2
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
