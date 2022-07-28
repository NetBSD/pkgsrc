# $NetBSD: Makefile,v 1.4 2022/07/28 22:16:16 fcambus Exp $

DISTNAME=	motyl-1.0.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}
GITHUB_PROJECT=	motyl
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fcambus/motyl/
COMMENT=	Opinionated blog-aware static site generator
LICENSE=	2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-mustache-[0-9]*:../../devel/ruby-mustache
DEPENDS+=	${RUBY_PKGPREFIX}-kramdown-[0-9]*:../../textproc/ruby-kramdown
DEPENDS+=	${RUBY_PKGPREFIX}-rouge-[0-9]*:../../www/ruby-rouge

NO_BUILD=	yes

REPLACE_RUBY=	bin/motyl

DOCDIR=		share/doc/motyl

INSTALLATION_DIRS+=	bin ${DOCDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/motyl ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
