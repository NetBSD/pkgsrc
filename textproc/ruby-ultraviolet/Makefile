# $NetBSD: Makefile,v 1.2 2010/05/07 08:34:23 ahoka Exp $

DISTNAME=	ultraviolet-0.10.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ultraviolet.rubyforge.org/
COMMENT=	Syntax highlighting engine based on Textpow

GEM_BUILD=	gemspec

DEPENDS+=       ${RUBY_PKGPREFIX}-textpow>=0.10.1:../../textproc/ruby-textpow

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
