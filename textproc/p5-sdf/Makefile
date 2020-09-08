# $NetBSD: Makefile,v 1.6 2020/09/08 13:16:45 wiz Exp $

DISTNAME=	sdf-2.001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IA/IANC/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://metacpan.org/source/IANC/sdf-2.001beta1
COMMENT=	Simple Document Format to generate multiple output formats
LICENSE=	2-clause-bsd

PERL5_PACKLIST=	auto/SDF/.packlist
USE_LANGUAGES=	# none

pre-configure:
	${FIND} ${WRKSRC} -type f -name '*.orig' -print | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
