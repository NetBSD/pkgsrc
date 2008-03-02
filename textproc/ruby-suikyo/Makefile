# $NetBSD: Makefile,v 1.1.1.1 2008/03/02 02:42:03 obache Exp $
#

.include "../../textproc/suikyo/Makefile.common"

PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://taiyaki.org/suikyo/ruby/index.html
COMMENT=	Suikyo for Ruby

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	suikyo-conv-table>=${SUIKYO_VER}:../../textproc/suikyo-conv-table
DEPENDS+=	suikyo-docs>=${SUIKYO_VER}:../../textproc/suikyo-docs

BUILD_DIRS+=	ruby

CONFIGURE_ARGS+=	--with-rubydir=${RUBY_SITELIBDIR}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
