# $NetBSD: Makefile,v 1.1.1.1 2006/11/17 15:45:46 obache Exp $
#

.include "../../textproc/hyperestraier/Makefile.common"

PKGNAME=	${RUBY_PKGPREFIX}-pure-hyperestraier-1.0.0.${HYPERESTRAIER_VERSION}
CATEGORIES=	textproc ruby

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://hyperestraier.sourceforge.net/
COMMENT=	Ruby pure interface of Hyper Estaier

MY_SUBDIR=	rubypure
BUILD_DIRS=	${MY_SUBDIR}
CONFIGURE_DIRS=	${MY_SUBDIR}

GNU_CONFIGURE=		yes
TEST_TARGET=		check
RUBY_HAS_ARCHLIB=	no

REPLACE_RUBY=	${MY_SUBDIR}/estcall.rb

.include "../../textproc/hyperestraier/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
