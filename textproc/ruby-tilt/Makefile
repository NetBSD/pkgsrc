# $NetBSD: Makefile,v 1.14 2017/09/10 16:11:16 taca Exp $

DISTNAME=	tilt-2.0.8
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtomayko/tilt/
COMMENT=	Generic interface to multiple Ruby template engines
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	rdoc:

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
