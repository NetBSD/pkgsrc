# $NetBSD: Makefile,v 1.3 2008/06/20 01:09:38 joerg Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

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
