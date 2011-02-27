# $NetBSD: Makefile,v 1.5.4.1 2011/02/27 00:26:28 tron Exp $

DISTNAME=	oniguruma-1.1.0
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oniguruma.rubyforge.org/
COMMENT=	Fast regular expression library
LICENSE=	modified-bsd

USE_TOOLS+=	pax

.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
