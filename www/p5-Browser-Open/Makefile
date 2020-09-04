# $NetBSD: Makefile,v 1.3 2020/09/04 14:20:29 wiz Exp $

DISTNAME=	Browser-Open-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/C/CF/CFRANKS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/C/CF/CFRANKS/
COMMENT=	Open a browser in a given URL
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Browser/Open/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
