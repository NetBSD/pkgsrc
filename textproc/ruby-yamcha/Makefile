# $NetBSD: Makefile,v 1.4 2012/10/25 06:56:59 asau Exp $
#

.include "../../textproc/yamcha/Makefile.common"

PKGREVISION=	1
CATEGORIES+=	ruby

COMMENT=	YamCha ruby module

USE_LANGUAGES=	c c++

USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	ruby

YAMCHA_LIBS_CMD=	${BUILDLINK_PREFIX.yamcha}/bin/yamcha-config --libs

post-extract:
	${SED} -e "s|@YAMCHA_LIBS@|`${YAMCHA_LIBS_CMD}`|g" \
		${WRKSRC}/ruby/extconf.rb.in > ${WRKSRC}/ruby/extconf.rb

BUILDLINK_API_DEPENDS.yamcha+=	yamcha>=${PKGVERSION_NOREV}
.include "../../textproc/yamcha/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
