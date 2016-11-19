# $NetBSD: Makefile,v 1.11 2016/11/19 15:40:08 taca Exp $

DISTNAME=	tilt-1.4.1
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/rtomayko/tilt/
COMMENT=	Generic interface to multiple Ruby template engines
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	rdoc:

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
