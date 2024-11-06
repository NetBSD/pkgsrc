# $NetBSD: Makefile,v 1.1 2024/11/06 15:50:11 taca Exp $

DISTNAME=	redcarpet-3.5.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/redcarpet/redcarpet35/}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vmg/redcarpet/
COMMENT=	Markdown that smells nice
LICENSE=	mit

RUBY_VERSIONS_ACCEPTED=	31

RUBYGEM_OPTIONS+=	--format-executable

OVERRIDE_GEMSPEC+=	:executables redcarpet=redcarpet35 \
			:files bin/redcarpet=bin/redcarpet35

pre-configure:
	${MV} ${WRKSRC}/bin/redcarpet ${WRKSRC}/bin/redcarpet35

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
