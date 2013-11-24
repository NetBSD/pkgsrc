# $NetBSD: Makefile,v 1.41 2013/11/24 15:26:30 taca Exp $

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-${RUBY_EXTNAME}-${RUBY_VERSION_FULL}
PKGREVISION=		1
RUBY_EXTNAME=		tk
CATEGORIES=		x11 ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby interface to the Tk widget set

USE_LANGUAGES=		c
USE_TOOLS+=		pax
USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	. tkutil
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/tk
WRKSRC=			${RUBY_WRKSRC}/ext/tk
CONFIGURE_ARGS+=	--with-X11-dir=${X11BASE:Q}

REPLACE_RUBY=		lib/tkextlib/pkg_checker.rb
REPLACE_RUBY_DIRS=	sample
INSTALLATION_DIRS=	${RUBY_EG}/tk

post-extract:
	${CHMOD} ${SHAREMODE} ${WRKSRC}/sample/tkextlib/tktable/tcllogo.gif

pre-install:
	cd ${WRKSRC}; \
	${FIND} . \( -name '*.bak' -o -name '*.orig' -o \
			-name '*.orig_dist' \) -exec ${RM} -f {} \;

post-install:
	cd ${WRKSRC}/sample; ${PAX} -rw . ${DESTDIR}${PREFIX}/${RUBY_EG}/tk

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
