# $NetBSD: Makefile,v 1.19 2022/06/28 11:36:45 wiz Exp $

DISTNAME=	XML-TreePP-0.43
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-TreePP
COMMENT=	Pure Perl 5 implementation for parsing/writing XML documents
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=			# empty
PERL5_PACKLIST=			auto/XML/TreePP/.packlist
CHECK_PORTABILITY_SKIP+=	make-dist.sh

DEPENDS+=	p5-libwww>=5.802:../../www/p5-libwww

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
