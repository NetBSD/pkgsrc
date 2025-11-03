# $NetBSD: Makefile,v 1.1 2025/11/03 05:15:27 taca Exp $

DISTNAME=	commonmarker-0.23.12
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/commonmarker/&0/}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gjtorikian/commonmarker
COMMENT=	CommonMark parser and renderer written in C, wrapped in Ruby
LICENSE=	mit

OVERRIDE_GEMSPEC+=	:executables commonmarker=commonmarker0 \
			:files bin/commonmarker=bin/commonmarker0
RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	${TEST} -f ${WRKSRC}/bin/commonmarker0 || \
		${MV} ${WRKSRC}/bin/commonmarker ${WRKSRC}/bin/commonmarker0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
