# $NetBSD: Makefile,v 1.7 2020/03/15 15:32:37 taca Exp $

DISTNAME=		tk-0.2.0
PKGREVISION=		1
CATEGORIES=		x11 ruby

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		https://github.com/ruby/tk
COMMENT=		Tk interface module using tcltklib
LICENSE=		2-clause-bsd

RUBY_VERSIONS_ACCEPTED=	24 25 26 27

CONFIGURE_ARGS+=	--with-X11-dir=${X11BASE:Q} \
			--with-X11-lib=${BUILDLINK_PREFIX.libX11}/lib

.include "../../lang/ruby/gem.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
