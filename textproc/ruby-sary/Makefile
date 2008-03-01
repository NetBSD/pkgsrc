# $NetBSD: Makefile,v 1.1.1.1 2008/03/01 08:30:48 obache Exp $
#

DISTNAME=	sary-ruby-1.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby-/-/}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://sary.sourceforge.net/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://sary.sourceforge.net/
COMMENT=	Ruby Binding of Sary

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes

DOCS=			Reference.en.rd Reference.ja.rd

SUBST_CLASSES+=		ruby
SUBST_STAGE.ruby=	post-build
SUBST_FILES.ruby=	${DOCS}
SUBST_SED.ruby=		-e 's|/usr/local/bin/ruby|${RUBY}|g'

INSTALLATION_DIRS=	${RUBY_DOCDIR}/sary

post-install:
.for d in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${d} ${DESTDIR}${RUBY_DOCDIR}/sary
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../textproc/sary/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
