# $NetBSD: Makefile,v 1.6 2010/09/10 08:25:17 taca Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../textproc/hyperestraier/Makefile.common"

PKGNAME=	${RUBY_PKGPREFIX}-pure-hyperestraier-1.0.0.${HYPERESTRAIER_VERSION}
PKGREVISION=	1
CATEGORIES=	textproc ruby

COMMENT=	Ruby pure interface of Hyper Estaier
LICENSE=	gnu-lgpl-v2.1

MY_SUBDIR=	rubypure
BUILD_DIRS=	${MY_SUBDIR}
CONFIGURE_DIRS=	${MY_SUBDIR}

GNU_CONFIGURE=		yes
TEST_TARGET=		check

REPLACE_RUBY=	${MY_SUBDIR}/estcall.rb

.include "../../textproc/hyperestraier/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
