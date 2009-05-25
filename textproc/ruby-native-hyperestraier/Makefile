# $NetBSD: Makefile,v 1.4 2009/05/25 09:48:50 obache Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../textproc/hyperestraier/Makefile.common"

PKGNAME=	${RUBY_PKGPREFIX}-native-hyperestraier-1.0.0.${HYPERESTRAIER_VERSION}
PKGREVISION=	1
CATEGORIES=	textproc ruby

COMMENT=	Ruby native interface of Hyper Estaier
LICENSE=	gnu-lgpl-v2.1

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
