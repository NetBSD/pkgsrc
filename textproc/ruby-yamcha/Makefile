# $NetBSD: Makefile,v 1.2.4.1 2011/02/27 00:26:29 tron Exp $
#

.include "../../textproc/yamcha/Makefile.common"

PKGREVISION=	1
CATEGORIES+=	ruby

COMMENT=	YamCha ruby module

PKG_DESTDIR_SUPPORT=	user-destdir

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
