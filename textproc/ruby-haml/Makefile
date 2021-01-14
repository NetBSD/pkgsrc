# $NetBSD: Makefile,v 1.22 2021/01/14 14:44:47 taca Exp $

DISTNAME=	haml-5.2.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://haml.info/
COMMENT=	XHTML & CSS markup language & template engine
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-temple>=0.8.0:../../textproc/ruby-temple
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=0:../../textproc/ruby-tilt

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
