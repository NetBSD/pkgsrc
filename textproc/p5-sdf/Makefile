# $NetBSD: Makefile,v 1.3 2019/09/16 06:50:28 schmonz Exp $

DISTNAME=	sdf-2.001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/I/IA/IANC/
COMMENT=	Simple Document Format to generate multiple output formats
LICENSE=	2-clause-bsd

PERL5_PACKLIST=	auto/SDF/.packlist
USE_LANGUAGES=	# none

pre-configure:
	${FIND} ${WRKSRC} -type f -name '*.orig' -print | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
