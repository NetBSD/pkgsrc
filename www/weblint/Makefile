# $NetBSD: Makefile,v 1.33 2021/02/02 09:13:36 wiz Exp $

DISTNAME=	weblint-1.020
PKGREVISION=	9
CATEGORIES=	www
MASTER_SITES=	http://www.perl.org/CPAN/authors/id/NEILB/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.weblint.org/
COMMENT=	HTML validator and sanity checker

CONFLICTS=	p5-HTML-Lint-[0-9]*

USE_TOOLS+=		perl:run
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

DEPENDS+=	p5-Perl4-CoreLibs-[0-9]*:../../devel/p5-Perl4-CoreLibs

.include "../../mk/bsd.pkg.mk"
