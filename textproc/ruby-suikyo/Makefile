# $NetBSD: Makefile,v 1.2 2008/06/19 14:57:45 taca Exp $
#

.include "../../textproc/suikyo/Makefile.common"

PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://taiyaki.org/suikyo/ruby/index.html
COMMENT=	Suikyo for Ruby

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	suikyo-conv-table>=${SUIKYO_VER}:../../textproc/suikyo-conv-table
DEPENDS+=	suikyo-docs>=${SUIKYO_VER}:../../textproc/suikyo-docs

BUILD_DIRS+=	ruby

CONFIGURE_ARGS+=	--with-rubydir=${PREFIX}/${RUBY_VENDORLIB}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
