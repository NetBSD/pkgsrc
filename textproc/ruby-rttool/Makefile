# $NetBSD: Makefile,v 1.19 2010/09/10 08:37:41 taca Exp $

DISTNAME=	rttool-1.0.3.0
CATEGORIES=	textproc

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.rubyist.net/~rubikitch/computer/rttool/
COMMENT=	RT to HTML (and hopefully LaTeX in future) table converter
LICENSE=	gnu-gpl-v2 OR ruby-license

CONFLICTS+=	ruby[1-9][0-9]-rttool-*

DEPENDS+=	${RUBY_PKGPREFIX}-rdtool>=0.6.18:../../textproc/ruby-rdtool

# Move the rt scripts into the main "bin" directory so they're
# automatically found and wrapped by the gem script during installation.
#
#pre-build:
#	cd ${WRKSRC}/bin && mv rt/* .
#	rmdir ${WRKSRC}/bin/rt

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
