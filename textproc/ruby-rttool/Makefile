# $NetBSD: Makefile,v 1.18 2008/04/04 15:22:20 jlam Exp $

DISTNAME=	rttool-1.0.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.rubyist.net/~rubikitch/computer/rttool/
COMMENT=	RT to HTML (and hopefully LaTeX in future) table converter

CONFLICTS+=	ruby[1-9][0-9]-rttool-*

DEPENDS+=	${RUBY_PKGPREFIX}-rdtool>=0.6.18:../../textproc/ruby-rdtool

GEM_BUILD=	gemspec

# Move the rt scripts into the main "bin" directory so they're
# automatically found and wrapped by the gem script during installation.
#
pre-build:
	cd ${WRKSRC}/bin && mv rt/* .
	rmdir ${WRKSRC}/bin/rt

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
