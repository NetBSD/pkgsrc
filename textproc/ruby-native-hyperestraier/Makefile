# $NetBSD: Makefile,v 1.2 2008/06/19 15:18:31 taca Exp $
#

.include "../../textproc/hyperestraier/Makefile.common"

PKGNAME=	${RUBY_PKGPREFIX}-native-hyperestraier-1.0.0.${HYPERESTRAIER_VERSION}
PKGREVISION=	1
CATEGORIES=	textproc ruby

COMMENT=	Ruby native interface of Hyper Estaier

MY_SUBDIR=	rubynative
BUILD_DIRS=	${MY_SUBDIR}
CONFIGURE_DIRS=	${MY_SUBDIR}

GNU_CONFIGURE=		yes
TEST_TARGET=		check
RUBY_HAS_ARCHLIB=	yes

REPLACE_RUBY=	${MY_SUBDIR}/estcmd.rb

.include "../../textproc/hyperestraier/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
