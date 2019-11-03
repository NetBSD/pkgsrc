# $NetBSD: Makefile,v 1.5 2019/11/03 09:14:18 rillig Exp $

DISTNAME=		tk-0.2.0
CATEGORIES=		x11 ruby

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		https://github.com/ruby/tk
COMMENT=		Tk interface module using tcltklib
LICENSE=		2-clause-bsd

RUBY_VERSIONS_ACCEPTED=	24 25 26

.include "../../lang/ruby/gem.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
