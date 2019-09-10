# $NetBSD: Makefile,v 1.1 2019/09/10 21:20:35 schmonz Exp $

DISTNAME=	sdf-2.001beta1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/I/IA/IANC/
COMMENT=	Simple Document Format to generate multiple output formats
LICENSE=	2-clause-bsd

PERL5_PACKLIST=	auto/SDF/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
