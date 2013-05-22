# $NetBSD: Makefile,v 1.6 2013/05/22 13:14:30 obache Exp $
#

.include "../../textproc/cabocha/Makefile.common"

CATEGORIES+=	ruby

COMMENT=	CaboCha ruby module

USE_LANGUAGES=	c c++

USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	ruby

BUILDLINK_API_DEPENDS.cabocha+=	cabocha>=${PKGVERSION_NOREV}
.include "../../textproc/cabocha/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
