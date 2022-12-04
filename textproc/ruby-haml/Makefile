# $NetBSD: Makefile,v 1.25 2022/12/04 15:56:11 taca Exp $

DISTNAME=	haml-6.0.12
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://haml.info/
COMMENT=	XHTML & CSS markup language & template engine
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-temple>=0.8.0:../../textproc/ruby-temple
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-tilt>=0:../../textproc/ruby-tilt

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
