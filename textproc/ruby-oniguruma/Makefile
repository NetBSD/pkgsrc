# $NetBSD: Makefile,v 1.1.1.1 2008/08/22 15:37:13 ahoka Exp $

DISTNAME=	oniguruma-1.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://oniguruma.rubyforge.org/
COMMENT=	Fast regular expression library

GEM_BUILD=	gemspec

.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
