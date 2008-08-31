# $NetBSD: Makefile,v 1.3 2008/08/31 21:46:40 ahoka Exp $

DISTNAME=	oniguruma-1.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://oniguruma.rubyforge.org/
COMMENT=	Fast regular expression library

PKG_DESTDIR_SUPPORT=	destdir

USE_TOOLS+=	pax
GEM_BUILD=	gemspec

.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
