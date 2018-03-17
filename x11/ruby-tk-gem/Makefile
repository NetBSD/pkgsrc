# $NetBSD: Makefile,v 1.3 2018/03/17 16:12:13 taca Exp $

DISTNAME=		tk-0.2.0
CATEGORIES=		x11 ruby

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		https://github.com/ruby/tk
COMMENT=		Tk interface module using tcltklib
LICENSE=		2-clause-bsd

RUBY_VERSIONS_ACCEPTED= 24 25

.include "../../lang/ruby/gem.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
