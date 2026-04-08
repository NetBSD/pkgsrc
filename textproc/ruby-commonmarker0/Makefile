# $NetBSD: Makefile,v 1.3 2026/04/08 14:29:35 taca Exp $

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

# This packages is for ruby-redmine50 and ruby-redmine60 and they are
# not support by ruby40.
RUBY_VERSIONS_ACCEPTED=	33 34

pre-configure:
	${TEST} -f ${WRKSRC}/bin/commonmarker0 || \
		${MV} ${WRKSRC}/bin/commonmarker ${WRKSRC}/bin/commonmarker0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
