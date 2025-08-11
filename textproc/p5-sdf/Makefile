# $NetBSD: Makefile,v 1.13 2025/08/11 16:51:51 schmonz Exp $

DISTNAME=	sdf-2.001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IA/IANC/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/sdf
COMMENT=	Simple Document Format to generate multiple output formats
LICENSE=	2-clause-bsd

DEPENDS+=	htmldoc-[0-9]*:../../www/htmldoc

PERL5_PACKLIST=	auto/SDF/.packlist
USE_LANGUAGES=	# none

pre-configure:
	${FIND} ${WRKSRC} -type f -name '*.orig' -print | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
