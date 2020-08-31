# $NetBSD: Makefile,v 1.2 2020/08/31 18:12:38 wiz Exp $

DISTNAME=	Browser-Open-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/C/CF/CFRANKS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/C/CF/CFRANKS/
COMMENT=	Open a browser in a given URL
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-parent>=0:../../devel/p5-parent

PERL5_PACKLIST=	auto/Browser/Open/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
