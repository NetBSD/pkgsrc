# $NetBSD: Makefile,v 1.4 2010/05/07 08:34:23 ahoka Exp $

DISTNAME=	oniguruma-1.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oniguruma.rubyforge.org/
COMMENT=	Fast regular expression library

PKG_DESTDIR_SUPPORT=	destdir

USE_TOOLS+=	pax
GEM_BUILD=	gemspec

.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
