# $NetBSD: Makefile,v 1.11 2012/09/15 10:06:38 obache Exp $
#

DISTNAME=	sary-ruby-1.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby-/-/}
PKGREVISION=	6
CATEGORIES=	textproc ruby
MASTER_SITES=	http://sary.sourceforge.net/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://sary.sourceforge.net/
COMMENT=	Ruby Binding of Sary
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_RUBY_EXTCONF=	yes
USE_TOOLS+=		pkg-config

DOCS=			Reference.en.rd Reference.ja.rd

SUBST_CLASSES+=		ruby
SUBST_STAGE.ruby=	post-build
SUBST_FILES.ruby=	${DOCS}
SUBST_SED.ruby=		-e 's|/usr/local/bin/ruby|${RUBY}|g'

INSTALLATION_DIRS=	${RUBY_DOC}/sary

post-install:
.for d in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${d} ${DESTDIR}${PREFIX}/${RUBY_DOC}/sary
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../textproc/sary/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
