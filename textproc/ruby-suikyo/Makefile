# $NetBSD: Makefile,v 1.3 2010/09/10 08:40:56 taca Exp $
#

.include "../../textproc/suikyo/Makefile.common"

PKGREVISION=	1

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://taiyaki.org/suikyo/ruby/index.html
COMMENT=	Suikyo for Ruby

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	suikyo-conv-table>=${SUIKYO_VER}:../../textproc/suikyo-conv-table
DEPENDS+=	suikyo-docs>=${SUIKYO_VER}:../../textproc/suikyo-docs


#
# The same dictonary directory now.
#
CONFLICTS+=	ruby[1-9][0-9]-suikyo-*
BUILD_DIRS+=	ruby

CONFIGURE_ARGS+=	--with-rubydir=${PREFIX}/${RUBY_VENDORLIB}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
