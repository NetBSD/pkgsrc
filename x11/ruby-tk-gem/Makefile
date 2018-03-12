# $NetBSD: Makefile,v 1.2 2018/03/12 11:17:57 wiz Exp $

DISTNAME=		tk-0.1.2
PKGREVISION=		1
CATEGORIES=		x11 ruby

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		https://github.com/ruby/tk
COMMENT=		Tk interface module using tcltklib
LICENSE=		2-clause-bsd

RUBY_VERSIONS_ACCEPTED= 24

.include "../../lang/ruby/gem.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
