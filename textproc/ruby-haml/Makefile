# $NetBSD: Makefile,v 1.32 2026/08/04 14:34:20 taca Exp $

DISTNAME=	haml-7.2.2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://haml.info/
COMMENT=	XHTML & CSS markup language & template engine
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-temple>=0.8.2:../../textproc/ruby-temple
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=0:../../textproc/ruby-tilt

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
