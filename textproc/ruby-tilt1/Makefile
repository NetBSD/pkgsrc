# $NetBSD: Makefile,v 1.1 2017/03/19 15:26:03 taca Exp $

DISTNAME=	tilt-1.4.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/tilt/tilt1/}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/rtomayko/tilt/
COMMENT=	Generic interface to multiple Ruby template engines
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	rdoc:

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
