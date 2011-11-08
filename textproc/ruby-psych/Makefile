# $NetBSD: Makefile,v 1.3 2011/11/08 16:33:36 taca Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-${RUBY_EXTNAME}-${RUBY_VERSION_FULL}
RUBY_EXTNAME=		psych
CATEGORIES=		textproc ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Ruby YAML parser and emitter

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_VERSION_SUPPORTED= 19
USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/psych
WRKSRC=			${RUBY_WRKSRC}/ext/psych

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
