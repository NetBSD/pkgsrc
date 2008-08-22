# $NetBSD: Makefile,v 1.1.1.1 2008/08/22 15:43:34 ahoka Exp $

DISTNAME=	ultraviolet-0.10.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://ultraviolet.rubyforge.org/
COMMENT=	Syntax highlighting engine based on Textpow

GEM_BUILD=	gemspec

DEPENDS+=       ${RUBY_PKGPREFIX}-textpow>=0.10.1:../../textproc/ruby-textpow

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
