# $NetBSD: Makefile,v 1.5 2015/03/08 14:07:43 taca Exp $
#

.include "../../textproc/suikyo/Makefile.common"

PKGREVISION=	1

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://taiyaki.org/suikyo/ruby/index.html
COMMENT=	Suikyo for Ruby

DEPENDS+=	suikyo-conv-table>=${SUIKYO_VER}:../../textproc/suikyo-conv-table
DEPENDS+=	suikyo-docs>=${SUIKYO_VER}:../../textproc/suikyo-docs

#
# The same dictonary directory now.
#
CONFLICTS+=	ruby[1-9][0-9]-suikyo-*
BUILD_DIRS+=	ruby

RUBY_VERSION_SUPPORTED= 18

CONFIGURE_ARGS+=	--with-rubydir=${PREFIX}/${RUBY_VENDORLIB}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
