# $NetBSD: Makefile,v 1.13 2017/07/30 22:32:24 wiz Exp $

DISTNAME=	tilt-2.0.7
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtomayko/tilt/
COMMENT=	Generic interface to multiple Ruby template engines
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	rdoc:

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
