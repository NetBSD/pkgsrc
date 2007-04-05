# $NetBSD: Makefile,v 1.2 2007/04/05 12:21:27 obache Exp $
#

.include "../../textproc/hyperestraier/Makefile.common"

PKGNAME=	${RUBY_PKGPREFIX}-pure-hyperestraier-1.0.0.${HYPERESTRAIER_VERSION}
CATEGORIES=	textproc ruby

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
