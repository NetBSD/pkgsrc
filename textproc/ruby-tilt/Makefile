# $NetBSD: Makefile,v 1.12 2017/03/19 15:30:00 taca Exp $

DISTNAME=	tilt-2.0.7
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/rtomayko/tilt/
COMMENT=	Generic interface to multiple Ruby template engines
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	rdoc:

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
