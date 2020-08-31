# $NetBSD: Makefile,v 1.4 2020/08/31 18:12:17 wiz Exp $

DISTNAME=	sdf-2.001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
