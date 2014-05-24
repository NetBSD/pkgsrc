# $NetBSD: Makefile,v 1.1 2014/05/24 10:21:13 obache Exp $
#

.include "../../textproc/marisa/Makefile.common"

CATEGORIES+=	ruby

COMMENT=	MARISA ruby module

USE_LANGUAGES=	c c++

USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	bindings/ruby

BUILDLINK_API_DEPENDS.marisa+=	marisa>=${PKGVERSION_NOREV}
.include "../../textproc/marisa/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
